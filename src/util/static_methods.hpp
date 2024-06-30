#ifndef STATIC_METHOD_H
#define STATIC_METHOD_H

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/hero_stats.hpp"
#include "variants/task_pull.hpp"

namespace godot{

class StaticMethods{

public:
    static void add_time(){
        GameController *controller = EternityData::get_singleton()->get_controller();
        if(controller == nullptr){
            UtilityFunctions::print("StaticMethods: controller is null");
            return;
        }
        if(!controller->has_int("game_time") || !controller->has_int("game_day")){
            UtilityFunctions::print("StaticMethods: controller not have game_time or game_day");
            return;
        }

        int time = controller->get_int("game_time");
        int day = controller->get_int("game_day");

        controller->put_int("lock_door", 0);
        
        if(time == 2){
            check_end(day+1);
            controller->put_int("game_time", 0);
            controller->put_int("game_day", day+1);
            update_hero();
        }
        else{
            controller->put_int("game_time", time+1);
        }
        

        if(EternityData::get_singleton()->get_hud() != nullptr){
            EternityData::get_singleton()->get_hud()->update_status();
        }else{
            UtilityFunctions::print("StaticMethods: hud is null");
        }
    }

    static void skip_day(){
        GameController *controller = EternityData::get_singleton()->get_controller();
        if(controller == nullptr){
            UtilityFunctions::print("StaticMethods: controller is null");
            return;
        }
        if(!controller->has_int("game_time") || !controller->has_int("game_day")){
            UtilityFunctions::print("StaticMethods: controller not have game_time or game_day");
            return;
        }

        int day = controller->get_int("game_day");
        check_end(day+1);

        controller->put_int("lock_door", 0);

        controller->put_int("game_time", 0);
        controller->put_int("game_day", day+1);
        update_hero();

        if(EternityData::get_singleton()->get_hud() != nullptr){
            EternityData::get_singleton()->get_hud()->update_status();
        }else{
            UtilityFunctions::print("StaticMethods: hud is null");
        }
    }

    static void check_end(int cur_day){
        if(cur_day < 3){
            return;
        }

        GameController *controller = EternityData::get_singleton()->get_controller();
        if(controller == nullptr){
            UtilityFunctions::print("StaticMethods: controller is null");
            return;
        }
        if(!controller->has_int("game_time") || !controller->has_int("game_day")){
            UtilityFunctions::print("StaticMethods: controller not have game_time or game_day");
            return;
        }


        if(cur_day >= 5){
            //controller->put_int("game_day", cur_day+1);
            end_game();
            return;
        }
        

        if(!controller->has_int(TaskPull::HairCut())){
            UtilityFunctions::print("StaticMethods: controller don't have haircut");
            return;
        }

        if(cur_day == 4 && controller->get_int(TaskPull::HairCut()) == 0){
            //controller->put_int("game_day", cur_day+1);
            end_game();
            return;
        }



        //if(cur_day == 3 && con)
    }

    static void update_hero(){
        if(EternityData::get_singleton()->get_selected_entity() == nullptr){
            UtilityFunctions::print("StaticMethods: selected hero is null");
            return;
        }

        if(EternityData::get_singleton()->get_selected_entity()->get_data() == nullptr){
            UtilityFunctions::print("StaticMethods: selected hero data is null");
            return;
        }
        EntityData *data = EternityData::get_singleton()->get_selected_entity()->get_data();
        
        if(!data->has_float(HeroStats::sleep()) || !data->has_float(HeroStats::hunger())){
            UtilityFunctions::print("StaticMethods: data haven't sleep or hunger");
            return;
        }

        float sleep = data->get_float(HeroStats::sleep());
        float hunger = data->get_float(HeroStats::hunger());

        data->put_float(HeroStats::sleep(), sleep - 0.4f);
        data->put_float(HeroStats::hunger(), hunger -= 0.2f);
    }

    static void spawn_node(Node3D *node, Vector3 position){
        if(EternityData::get_singleton()->get_controller() == nullptr){
            UtilityFunctions::print("StaticMethods: controller is null");
            return;
        }
        Node* scene = EternityData::get_singleton()->get_controller()->get_current_scene();
        if(scene == nullptr){
            UtilityFunctions::print("StaticMethods: scene is null");
            return;
        }

        scene->add_child(node);
        node->set_global_position(position);
    }

    static void end_game(){
        // if(EternityData::get_singleton()->get_controller() == nullptr){
        //     UtilityFunctions::print("StaticMethods: controller is null");
        //     return;
        // }

        String model_path = Util::get_value_from_config("util", "end_game_screen");

        Node *node = Util::spawn_node(model_path);
        if(node == nullptr){
            UtilityFunctions::print("ViewModelInteractor: node is not created");
            return;
        }

        ViewModel *model = Object::cast_to<ViewModel>(node);
        if(!model){
            UtilityFunctions::print("ViewModelInteractor: node is not a viewModel");
            return;
        }

        Hud* hud = EternityData::get_singleton()->get_hud();

        if(hud == nullptr){
            UtilityFunctions::print("ViewModelInteractor: hud is null");
            return;
        }

        hud->add_child(model);
        model->open_window(nullptr, nullptr);

        // GameController *controller = EternityData::get_singleton()->get_controller();

        // if(!controller->has_int(TaskPull::AppsCheck()) || 
        //         !controller->has_int(TaskPull::HairCut()) || 
        //         !controller->has_int(TaskPull::Project())  || 
        //         !controller->has_int("game_day")){
        //     UtilityFunctions::print("StaticMethods: controller don't have vars");
        //     return;
        // }

        // UtilityFunctions::print("Game end");
        // UtilityFunctions::print("Day: ", UtilityFunctions::var_to_str(controller->get_int("game_day") + 1));
        // UtilityFunctions::print("Your tasks: ");
        // UtilityFunctions::print("Project: ", UtilityFunctions::var_to_str(controller->get_int(TaskPull::Project())));
        // UtilityFunctions::print("AppCheck: ", UtilityFunctions::var_to_str(controller->get_int(TaskPull::AppsCheck())));
        // UtilityFunctions::print("HairCut: ", UtilityFunctions::var_to_str(controller->get_int(TaskPull::HairCut())));
    }
    
};

}

#endif // ENTITY_PARAMS_H
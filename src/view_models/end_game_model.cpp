#include "end_game_model.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/task_pull.hpp"

void godot::EndGameModel::_bind_methods()
{
    
    ClassDB::bind_method(D_METHOD("set_result_path"), &EndGameModel::set_result_path);
    ClassDB::bind_method(D_METHOD("get_result_path"), &EndGameModel::get_result_path);

    ClassDB::bind_method(D_METHOD("set_main_info_path"), &EndGameModel::set_main_info_path);
    ClassDB::bind_method(D_METHOD("get_main_info_path"), &EndGameModel::get_main_info_path);
    

    ClassDB::add_property("EndGameModel", PropertyInfo(Variant::NODE_PATH, "result_path"), "set_result_path", "get_result_path");
    ClassDB::add_property("EndGameModel", PropertyInfo(Variant::NODE_PATH, "main_info_path"), "set_main_info_path", "get_main_info_path");
}

void godot::EndGameModel::init_links()
{
    if(has_node(main_info_path) && get_node<RichTextLabel>(main_info_path)){
        this->main_info = get_node<RichTextLabel>(main_info_path);
    }
    else{
        UtilityFunctions::print("EndGameModel: main_info_path so bad");
    }

    if(has_node(result_path) && get_node<Label>(result_path)){
        this->result_info = get_node<Label>(result_path);
    }
    else{
        UtilityFunctions::print("EndGameModel: result_path so bad");
    }
}

void godot::EndGameModel::update_info()
{
    if(main_info == nullptr || result_info == nullptr){
        UtilityFunctions::print("EndGameModel: result or info is null");
        return;
    }

    GameController *controller = EternityData::get_singleton()->get_controller();

    if(controller == nullptr){
        UtilityFunctions::print("EndGameModel: controller is null");
        return;
    }

    if(!controller->has_int(TaskPull::AppsCheck()) || !controller->has_int(TaskPull::HairCut()) || !controller->has_int(TaskPull::Project()) || !controller->has_int("game_day")){
        UtilityFunctions::print("EndGameModel: controller dont have some vars");
        return;
    }

    int cur_day = controller->get_int("game_day")+1;
    UtilityFunctions::print("EndGameModel: day: ", UtilityFunctions::var_to_str(cur_day));

    int apps_check = controller->get_int(TaskPull::AppsCheck());
    int HairCut = controller->get_int(TaskPull::HairCut());
    int Project = controller->get_int(TaskPull::Project());

    String result = "win";

    if(apps_check == 0){
        result = "lose";
    }
    if(HairCut == 0){
        result = "lose";
    }
    if(Project < 4){
        result = "lose";
    }

    result_info->set_text(Util::get_value_from_config("word", result));

    String info = "";
    info += Util::get_value_from_config("word", "project") + bool_to_str(Project >= 4) + "\n";
    info += Util::get_value_from_config("word", "hair_cut") + bool_to_str(HairCut != 0) + "\n";
    info += Util::get_value_from_config("word", "apps_check") + bool_to_str(apps_check != 0) + "\n";
    info += Util::get_value_from_config("word", "days") + UtilityFunctions::var_to_str(cur_day);

    main_info->set_text(info);
    
}

godot::String godot::EndGameModel::bool_to_str(bool param)
{
    if(param){
        return Util::get_value_from_config("word", "done");
    }
    return Util::get_value_from_config("word", "failed");
}

void godot::EndGameModel::set_main_info_path(NodePath p_main_info_path)
{
    this->main_info_path = p_main_info_path;
}

godot::NodePath godot::EndGameModel::get_main_info_path()
{
    return this->main_info_path;
}

void godot::EndGameModel::set_result_path(NodePath p_result_path)
{
    this->result_path = p_result_path;
}

godot::NodePath godot::EndGameModel::get_result_path()
{
    return this->result_path;
}

void godot::EndGameModel::_open_window(Entity *interaction, Entity *interactor)
{
    UtilityFunctions::print("EndGameModel: start pos");
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("EndGameModel: hud is null");
        return;
    }

    hud->lock_game();
    set_physics_process_internal(true);

    init_links();
    update_info();
    
}

void godot::EndGameModel::_close_window()
{
    get_tree()->quit();
}

void godot::EndGameModel::_int_process()
{
    if(Input::get_singleton()->is_action_just_released("e_cancel") && timer-- <= 0.0f){
        close_window();
    }
}

#include "project_work_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::ProjectWorkInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_sound_key"), &ProjectWorkInteractor::set_sound_key);

    ClassDB::bind_method(D_METHOD("set_step_two"), &ProjectWorkInteractor::set_step_two);
    ClassDB::bind_method(D_METHOD("set_step_four"), &ProjectWorkInteractor::set_step_four);
}

bool godot::ProjectWorkInteractor::is_avaible(GameController *controller)
{
    if(!controller->has_int("last_project_time") || !controller->has_int("last_project_day") ){
        UtilityFunctions::print("ProjectWorkInteractor: create vars");

        controller->put_int("last_project_time", controller->get_int("game_time"));
        controller->put_int("last_project_day", controller->get_int("game_day"));

        return true;
    }

    
    if(controller->get_int("last_project_time") == controller->get_int("game_time") && 
            controller->get_int("last_project_day") == controller->get_int("game_day")){
        
        UtilityFunctions::print("ProjectWorkInteractor: not now");
        return false;
    }

    controller->put_int("last_project_time", controller->get_int("game_time"));
    controller->put_int("last_project_day", controller->get_int("game_day"));
    return true;
}

void godot::ProjectWorkInteractor::set_step_two(String p_step_two)
{
    this->step_two = p_step_two;
}

void godot::ProjectWorkInteractor::set_step_four(String p_step_four)
{
    this->step_four = p_step_four;
}

void godot::ProjectWorkInteractor::set_sound_key(String p_sound_key)
{
    this->sound_key = p_sound_key;
}

void godot::ProjectWorkInteractor::spawn_game(String model_path, Entity *p_entity)
{
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
    model->open_window(get_entity(), p_entity);
}

bool godot::ProjectWorkInteractor::_interact(Entity *p_entity)
{
    if(EternityData::get_singleton()->get_controller() == nullptr){
        UtilityFunctions::print("ProjectWorkInteractor: controller is null");
        return false;
    }

    GameController *controller = EternityData::get_singleton()->get_controller();
    if(!controller->has_int("project_progress")){
        UtilityFunctions::print("ProjectWorkInteractor: controller doesn't have key: project_progress");
        return false;
    }

    if(!controller->has_int("game_time") || !controller->has_int("game_day")){
        UtilityFunctions::print("ProjectWorkInteractor: controller doesn't have key: game_time or game_day");
        return false;
    }
    if(!is_avaible(controller)){
        return false;
    }

    int step = controller->get_int("project_progress");
    
    UtilityFunctions::print("ProjectWorkInteractor: work on project");
    if(step == 0){
        controller->put_int("lock_door", 1);
        UtilityFunctions::print("ProjectWorkInteractor: lock_door: ", controller->get_int("lock_door"));
    }
    else if(step == 1){
        spawn_game(step_two, p_entity);
        StaticMethods::add_time();
    }
    else if(step == 2){
        controller->put_int("lock_door", 1);
        UtilityFunctions::print("ProjectWorkInteractor: lock_door: ", controller->get_int("lock_door"));
    }
    else if(step == 3){
        spawn_game(step_four, p_entity);
        StaticMethods::add_time();
    }
    else{
        return false;
    }

    controller->put_int("project_progress", step+1);
    UtilityFunctions::print(controller->get_int("project_progress"));

    if(sound_key != String())
        StaticMethods::play_sound(sound_key);

    return true;
    
}

godot::Interaction *godot::ProjectWorkInteractor::_clone()
{
    return memnew(ProjectWorkInteractor);
}

godot::ProjectWorkInteractor::ProjectWorkInteractor()
{
}

godot::ProjectWorkInteractor::~ProjectWorkInteractor()
{
}

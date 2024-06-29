#include "project_work_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::ProjectWorkInteractor::_bind_methods()
{
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
        
    }
    else if(step == 2){
        controller->put_int("lock_door", 1);
    }
    else{
        
    }

    controller->put_int("project_progress", step+1);
    UtilityFunctions::print(controller->get_int("project_progress"));

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

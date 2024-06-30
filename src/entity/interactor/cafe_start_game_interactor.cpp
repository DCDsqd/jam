#include "cafe_start_game_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::CaffeStartGameInteractor::_bind_methods()
{
}

bool godot::CaffeStartGameInteractor::_interact(Entity *p_entity)
{
    if(activate)
        return false;

    GameController *game_controller = EternityData::get_singleton()->get_controller();
    if(game_controller == nullptr){
        UtilityFunctions::print("CaffeStartGameInteractor: controller is null");
        return false;
    }

    Node *scene = game_controller->get_current_scene();
    if(scene == nullptr){
        UtilityFunctions::print("CaffeStartGameInteractor: scene is null");
        return false;
    }

    if(!scene->find_child("CaffeController")){
        UtilityFunctions::print("CaffeStartGameInteractor: not found child: CaffeController");
        return false;
    }
    CaffeController *controller = cast_to<CaffeController>(scene->find_child("CaffeController"));
    if(controller == nullptr){
        UtilityFunctions::print("CaffeStartGameInteractor: node CaffeController not a CaffeController");
        return false;
    }

    controller->start_game(p_entity);
    activate = true;
    return true;
}

godot::Interaction *godot::CaffeStartGameInteractor::_clone()
{
    return nullptr;
}

godot::CaffeStartGameInteractor::CaffeStartGameInteractor()
{
}

godot::CaffeStartGameInteractor::~CaffeStartGameInteractor()
{
}

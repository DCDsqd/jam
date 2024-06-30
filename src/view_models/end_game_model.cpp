#include "end_game_model.h"
#include "godot_cpp/variant/utility_functions.hpp"

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
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->lock_game();
    set_physics_process_internal(true);

}

void godot::EndGameModel::_close_window()
{
    
}

void godot::EndGameModel::_int_process()
{
    if(Input::get_singleton()->is_action_just_released("e_cancel") && timer-- <= 0.0f){
        close_window();
    }
}

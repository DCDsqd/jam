#include "simple_view_model.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::SimpleViewModel::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_param"), &SimpleViewModel::set_param);
}

void godot::SimpleViewModel::set_param(float p_param)
{
    this->param = p_param;
}

void godot::SimpleViewModel::_open_window(Entity *interaction, Entity *interactor)
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->lock_game();

}

void godot::SimpleViewModel::_close_window()
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->unlock_game();

}

void godot::SimpleViewModel::_int_process()
{
    
}

#include "jump_mini_game.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::JumpMiniGame::calculate_score()
{

    float result = start_value + score*modifier;

    EntityData* data = player->get_data();

    if(!data->has_float(param)){
        data->put_float(param, result);
        return;
    }

    float tmp = data->get_float(param);
    data->put_float(param, tmp + result);
    
}

void godot::JumpMiniGame::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_skip_day"), &JumpMiniGame::set_skip_day);
    ClassDB::bind_method(D_METHOD("set_add_time"), &JumpMiniGame::set_add_time);

    ClassDB::bind_method(D_METHOD("set_param"), &JumpMiniGame::set_param);
    ClassDB::bind_method(D_METHOD("set_modifier"), &JumpMiniGame::set_modifier);
    ClassDB::bind_method(D_METHOD("set_start_value"), &JumpMiniGame::set_start_value);

    ClassDB::bind_method(D_METHOD("get_score"), &JumpMiniGame::get_score);
    ClassDB::bind_method(D_METHOD("get_health"), &JumpMiniGame::get_health);
    ClassDB::bind_method(D_METHOD("minus_hp"), &JumpMiniGame::minus_hp);
    ClassDB::bind_method(D_METHOD("add_score"), &JumpMiniGame::add_score);
}

void godot::JumpMiniGame::_open_window(Entity *interaction, Entity *interactor)
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    this->player = interactor;

    hud->lock_game();

}

void godot::JumpMiniGame::_close_window()
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->unlock_game();

    if(player != nullptr && player->get_data() != nullptr){
        calculate_score();
        player->emit_signal("on_buffs_change");
    }else{
        UtilityFunctions::print("JumpMiniGame: player or player data is null");
    }

    if(skip_day){
        StaticMethods::skip_day();
        return;
    }

    if(add_time){
        StaticMethods::add_time();
        return;
    }


}

void godot::JumpMiniGame::_int_process()
{

}

void godot::JumpMiniGame::set_skip_day(bool p_skip_day)
{
    this->skip_day = p_skip_day;
}

void godot::JumpMiniGame::set_add_time(bool p_add_time)
{
    this->add_time = p_add_time;
}

void godot::JumpMiniGame::set_param(String p_param)
{
    this->param = p_param;
}

void godot::JumpMiniGame::set_modifier(float p_modifier)
{
    this->modifier = p_modifier;
}

void godot::JumpMiniGame::set_start_value(float p_start_value)
{
    this->start_value = p_start_value;
}

int godot::JumpMiniGame::get_score()
{
    return this->score;
}

int godot::JumpMiniGame::get_health()
{
    return this->health;
}

void godot::JumpMiniGame::add_score()
{
    this->score ++;
}

void godot::JumpMiniGame::minus_hp()
{
    this->health--;
    if(health <= 0){
        close_window();
    }
}

#include "jump_mini_game.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::JumpMiniGame::calculate_score()
{
    EntityData* data = player->get_data();

    if(!data->has_float(HeroStats::chill())){
        data->put_float(HeroStats::chill(), score);
        return;
    }

    float chill = data->get_float(HeroStats::chill());
    data->put_float(HeroStats::chill(), chill + score);
    
}

void godot::JumpMiniGame::_bind_methods()
{
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

}

void godot::JumpMiniGame::_int_process()
{

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

#include "shading_view_model.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::ShadingViewModel::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_message"), &ShadingViewModel::set_message);
    ClassDB::bind_method(D_METHOD("add_plus_score"), &ShadingViewModel::add_plus_score);
}

void godot::ShadingViewModel::calculate_score()
{
    UtilityFunctions::print("calculate score");
    EntityData *data = player->get_data();

    for(auto i : plus_score){
        if(data->has_float(i.key)){
            float tmp = data->get_float(i.key) + i.value;
            UtilityFunctions::print("ShadingViewModel: setting new stat, by key: ", i.key, " value: ", tmp);
            data->put_float(i.key, tmp);
        }
        else{
            UtilityFunctions::print("ShadingViewModel: data doesn't have key: ", i.key);
        }
    }
}

void godot::ShadingViewModel::set_message(String p_message)
{
    this->message = p_message;
}

void godot::ShadingViewModel::add_plus_score(String key, float value)
{
    plus_score[key] = value;
}

void godot::ShadingViewModel::_open_window(Entity *interaction, Entity *interactor)
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("ShadingViewModel: hud is null");
        return;
    }

    if(get_child_count() == 0){
        UtilityFunctions::print("ShadingViewModel: zero children(");
        return;
    }

    Control *p_control = cast_to<Control>(get_child(0));
    if(!p_control){
        UtilityFunctions::print("ShadingViewModel: child not a control");
        return;
    }

    control = p_control;

    this->player = interactor;

    hud->lock_game();

    this->shading = false;
    this->start = true;
    set_physics_process_internal(true);
}

void godot::ShadingViewModel::_close_window()
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

    if(message != String())
        StaticMethods::spawn_message(message, 1);
}

void godot::ShadingViewModel::_int_process()
{
    if(start && shading < 1.0f){
        shading += 0.05f;
        if(control != nullptr){
            Color color = control->get_modulate();
            color.a = shading;
            control->set_modulate(color);
        }
    }
    else if (start && shading >= 1.0f){
        start = false;
    }
    else if(!start && shading > 0.0f){
        shading -= 0.05f;
        if(control != nullptr){
            Color color = control->get_modulate();
            color.a = shading;
            control->set_modulate(color);
        }
    }
    else{
        close_window();
    }

}

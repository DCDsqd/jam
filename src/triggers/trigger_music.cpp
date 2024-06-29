#include "trigger_music.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::TriggerMusic::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_music"), &TriggerMusic::set_music);
	ClassDB::bind_method(D_METHOD("get_music"), &TriggerMusic::get_music);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "music"), "set_music", "get_music");
}

bool godot::TriggerMusic::_activate()
{
    if(EternityData::get_singleton()->get_music_controller() == nullptr){
        UtilityFunctions::print("TriggerMusic: music_controller is null");
        return false;
    }

    EternityData::get_singleton()->get_music_controller()->swap_music(music);
    return true;
}

void godot::TriggerMusic::set_music(String p_music)
{
    this->music = p_music;
}

godot::String godot::TriggerMusic::get_music()
{
    return this->music;
}

godot::TriggerMusic::TriggerMusic()
{
}

godot::TriggerMusic::~TriggerMusic()
{
}

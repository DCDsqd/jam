#include "trigger_sound.h"
#include "util/static_methods.hpp"

void godot::TriggerSound::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_sound"), &TriggerSound::set_sound);
    ClassDB::bind_method(D_METHOD("get_sound"), &TriggerSound::get_sound);

    ClassDB::add_property("TriggerSound", PropertyInfo(Variant::STRING, "marker"), "set_sound", "get_sound");
}

void godot::TriggerSound::set_sound(String p_sound)
{
    this->sound = p_sound;
}

godot::String godot::TriggerSound::get_sound()
{
    return this->sound;
}

bool godot::TriggerSound::_activate()
{
    if(sound != String())
        StaticMethods::play_sound(sound);
        
    return true;
}

godot::TriggerSound::TriggerSound()
{
}

godot::TriggerSound::~TriggerSound()
{
}

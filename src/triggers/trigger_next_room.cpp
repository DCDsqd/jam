#include "trigger_next_room.h"

void godot::TriggerNextRoom::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_next_scene"), &TriggerNextRoom::set_next_scene);
	ClassDB::bind_method(D_METHOD("get_next_scene"), &TriggerNextRoom::get_next_scene);
	ClassDB::add_property("TriggerNextRoom", PropertyInfo(Variant::STRING, "next_scene"), "set_next_scene", "get_next_scene");
}

bool godot::TriggerNextRoom::_activate()
{
	//EternityData::get_singleton()->get_controller()->save_point("auto");
	EternityData::get_singleton()->get_controller()->swap_scene(next_scene);

    return true;
}

void godot::TriggerNextRoom::set_next_scene(String p_next_scene)
{
    this->next_scene = p_next_scene;
}

godot::String godot::TriggerNextRoom::get_next_scene()
{
    return this->next_scene;
}

godot::TriggerNextRoom::TriggerNextRoom()
{
}

godot::TriggerNextRoom::~TriggerNextRoom()
{
}

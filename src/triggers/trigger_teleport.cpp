#include "trigger_teleport.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::TriggerTeleport::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_marker"), &TriggerTeleport::set_marker);
    ClassDB::bind_method(D_METHOD("get_marker"), &TriggerTeleport::get_marker);
    
    ClassDB::bind_method(D_METHOD("set_obj"), &TriggerTeleport::set_obj);
    ClassDB::bind_method(D_METHOD("get_obj"), &TriggerTeleport::get_obj);

    ClassDB::add_property("TriggerTeleport", PropertyInfo(Variant::NODE_PATH, "marker"), "set_marker", "get_marker");
    ClassDB::add_property("TriggerTeleport", PropertyInfo(Variant::NODE_PATH, "obj"), "set_obj", "get_obj");
}

bool godot::TriggerTeleport::_activate()
{
    if(!has_node(marker) || !has_node(obj)){
        UtilityFunctions::print("TriggerTeleport: marker or obj not exist");
        return false;
    }

    if(!get_node<Node3D>(marker) || !get_node<Node3D>(obj)){
        UtilityFunctions::print("TriggerTeleport: marker or obj not 3d");
        return false;
    }

    get_node<Node3D>(obj)->set_position(get_node<Node3D>(marker)->get_position());
    return true;
}

void godot::TriggerTeleport::set_marker(NodePath p_marker)
{
    this->marker = p_marker;
}

godot::NodePath godot::TriggerTeleport::get_marker()
{
    return this->marker;
}

void godot::TriggerTeleport::set_obj(NodePath p_obj)
{
    this->obj = p_obj;
}

godot::NodePath godot::TriggerTeleport::get_obj()
{
    return this->obj;
}

godot::TriggerTeleport::TriggerTeleport()
{
}

godot::TriggerTeleport::~TriggerTeleport()
{
}

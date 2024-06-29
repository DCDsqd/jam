#include "trigger_camera_target.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::TriggerCameraTarget::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_marker"), &TriggerCameraTarget::set_marker);
    ClassDB::bind_method(D_METHOD("get_marker"), &TriggerCameraTarget::get_marker);

    ClassDB::add_property("TriggerCameraTarget", PropertyInfo(Variant::NODE_PATH, "marker"), "set_marker", "get_marker");
}

bool godot::TriggerCameraTarget::_activate()
{

    if( EternityData::get_singleton()->get_camera() == nullptr){
        UtilityFunctions::print("TriggerCameraTarget: camera is null");
        return false;
    }
    if(!has_node(marker)){
        UtilityFunctions::print("TriggerCameraTarget: marker is not exist");
        return false;
    }
    if(!get_node<Node3D>(marker)){
        UtilityFunctions::print("TriggerCameraTarget: marker is not 3d");
        return false;
    }

    EternityData::get_singleton()->get_camera()->set_target(get_node<Node3D>(marker));

    return true;
}

void godot::TriggerCameraTarget::set_marker(NodePath p_marker)
{
    this->marker = p_marker;
}

godot::NodePath godot::TriggerCameraTarget::get_marker()
{
    return this->marker;
}

godot::TriggerCameraTarget::TriggerCameraTarget()
{
}

godot::TriggerCameraTarget::~TriggerCameraTarget()
{
}

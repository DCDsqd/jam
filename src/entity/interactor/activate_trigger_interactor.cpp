#include "activate_trigger_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::ActivateTriggerInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_trigger"), &ActivateTriggerInteractor::set_trigger);
}

void godot::ActivateTriggerInteractor::set_trigger(String p_trigger_name)
{
    this->trigger_name = p_trigger_name;
}

bool godot::ActivateTriggerInteractor::_interact(Entity *p_entity)
{
    GameController *controller = EternityData::get_singleton()->get_controller();
    if(controller == nullptr){
        UtilityFunctions::print("ActivateTriggerInteractor: controller is null");
        return false;
    }

    Trigger3D *trigger = controller->get_trigger(trigger_name);

    if(trigger == nullptr){
        UtilityFunctions::print("ActivateTriggerInteractor: trigger not found");
        return false;
    }

    trigger->activate();

    return true;
}

godot::Interaction *godot::ActivateTriggerInteractor::_clone()
{
    return new ActivateTriggerInteractor();
}

godot::ActivateTriggerInteractor::ActivateTriggerInteractor()
{
}

godot::ActivateTriggerInteractor::~ActivateTriggerInteractor()
{
}

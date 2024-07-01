#include "trigger_new_day.h"
#include "util/static_methods.hpp"

void godot::TriggerNewDay::_bind_methods()
{
}

bool godot::TriggerNewDay::_activate()
{
    StaticMethods::add_time();
    return true;
}

godot::TriggerNewDay::TriggerNewDay()
{
}

godot::TriggerNewDay::~TriggerNewDay()
{
}

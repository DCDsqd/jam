#include "param_button.h"

void godot::ParamButton::_bind_methods()
{
    ADD_SIGNAL(MethodInfo("param_activate", PropertyInfo(Variant::INT, "num")));
}


void godot::ParamButton::set_num(int p_num)
{
    this->num = p_num;
}

void godot::ParamButton::_pressed()
{
    emit_signal("param_activate", num);
}

godot::ParamButton::ParamButton()
{
}

godot::ParamButton::~ParamButton()
{
}

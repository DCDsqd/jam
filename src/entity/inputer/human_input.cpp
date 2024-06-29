#include "human_input.h"
#include "godot_cpp/classes/eternity_data.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::HumanInput::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("set_select_entity"), &HumanInput::set_select_entity);
}

void godot::HumanInput::_int_process()
{
    move();
    interact();
}

void godot::HumanInput::_on_death()
{
}

void godot::HumanInput::_set_entity()
{
	UtilityFunctions::print("HumanInput: _set_entity");
	if(select_entity){
		UtilityFunctions::print("HumanInput: select new entity");
		EternityData::get_singleton()->select_entity(get_entity()->get_entity());
	}
		
}

void godot::HumanInput::set_select_entity(bool p_select_entity)
{
	this->select_entity = p_select_entity;
}

void godot::HumanInput::move()
{
    if (get_entity() == nullptr) {
        return;
		//delete this;
	}

	Vector2 dir = input->get_vector("e_left", "e_right", "e_up", "e_down");
	bool jump = input->is_action_pressed("e_space");
	get_entity()->move(Vector3(dir.x, 0, dir.y), jump);
}

void godot::HumanInput::interact()
{
    if (get_entity() == nullptr) {
		return;
		//delete this;
	}
	if (input->is_action_just_released("e_interact")) {
		this->get_entity()->interact_to();
	}
}


godot::HumanInput::HumanInput()
{
    this->input = Input::get_singleton();

}

godot::HumanInput::~HumanInput()
{
}

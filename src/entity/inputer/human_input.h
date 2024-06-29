#ifndef HUMAN_INPUT_H
#define HUMAN_INPUT_H
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/void_input.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/moving_entity.hpp>

namespace godot {

class HumanInput : public VoidInput {
	GDCLASS(HumanInput, VoidInput)

private:
	double time_passed;
	Input *input = nullptr;
	bool select_entity = false;

protected:
	static void _bind_methods();

public:
	void _int_process() override;
	void _on_death() override;
	void _set_entity() override;

	void set_select_entity(bool p_select_entity);

	void move();
	void interact();

	HumanInput();
	~HumanInput();
};

}

#endif //HUMAN_INPUT_H
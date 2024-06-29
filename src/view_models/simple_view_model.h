#ifndef PART_TIME_MODEL_H
#define PART_TIME_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>

namespace godot {

class SimpleViewModel : public ViewModel {
	GDCLASS(SimpleViewModel, ViewModel)

protected:
    static void _bind_methods();
	float param = 0.0f;

public:
	void set_param(float p_param);

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

};
}


#endif // PART_TIME_MODEL_H
#ifndef NEW_DAY_MODEL_H
#define NEW_DAY_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/util.hpp>

namespace godot {

class NewDayModel : public ViewModel {
	GDCLASS(NewDayModel, ViewModel)

protected:
    static void _bind_methods();

    Label *new_day = nullptr;
	NodePath new_day_path;

	Label *old_day = nullptr;
	NodePath old_day_path;

	int step = 0;
	float timer = 0.0f;

	void init_links();
	void set_days();

public:
	void set_new_day_path(NodePath p_new_day_path);
	NodePath get_new_day_path();

	void set_old_day_path(NodePath p_old_day_path);
	NodePath get_old_day_path();

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

};
}


#endif // NEW_DAY_MODEL_H
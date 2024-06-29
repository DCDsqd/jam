#ifndef MULTI_SELECTOR_MODEL_H
#define MULTI_SELECTOR_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/templates/pair.hpp>

#include "util/param_button.h"

#include <vector>

namespace godot {

class MultiSelectorModel : public ViewModel {
	GDCLASS(MultiSelectorModel, ViewModel)

protected:
    static void _bind_methods();

	std::vector<Pair<String, Interaction*>> interactors;

	Entity* tmp_interaction = nullptr;
	Entity* tmp_interactor = nullptr;

	NodePath start_pos_path;
	Vector2 offset;

public:
	void add_interactor(String name, Interaction *interactor);
	void set_start_pos(NodePath p_start_pos_path);
	NodePath get_start_pos();
	void set_offset(Vector2 p_offset);

	void select_option(int num);

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

	MultiSelectorModel();
	~MultiSelectorModel();
};
}


#endif // MULTI_SELECTOR_MODEL_H
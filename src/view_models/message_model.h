#ifndef USE_IMPACT_MODEL_H
#define USE_IMPACT_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/classes/animated_texture.hpp>

namespace godot {

class MessageModel : public ViewModel {
	GDCLASS(MessageModel, ViewModel)

protected:
    static void _bind_methods();

	String message;

	NodePath label_path;
	NodePath texture_path;

	float timer = 180.0f;

public:
	void set_label_path(NodePath p_label_path);
	NodePath get_label_path();
	void set_texture_path(NodePath p_texture_path);
	NodePath get_texture_path();

	void set_message(String message, int type);

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

	MessageModel();
	~MessageModel();
};
}


#endif // USE_IMPACT_MODEL_H
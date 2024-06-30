#ifndef END_GAME_MODEL_H
#define END_GAME_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/rich_text_label.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

namespace godot {

class EndGameModel : public ViewModel {
	GDCLASS(EndGameModel, ViewModel)

protected:
    static void _bind_methods();

    RichTextLabel *main_info;
    Label *result_info;

    NodePath main_info_path;
    NodePath result_path;

    float timer;

    void init_links();
    void update_info();

    String bool_to_str(bool param);

public:
    void set_main_info_path(NodePath p_main_info_path);
    NodePath get_main_info_path();
    void set_result_path(NodePath p_result_path);
    NodePath get_result_path();

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

};
}


#endif // END_GAME_MODEL_H
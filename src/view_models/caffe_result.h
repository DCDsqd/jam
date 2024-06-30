#ifndef CAFFE_RESULT_H
#define CAFFE_RESULT_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/rich_text_label.hpp>
#include <godot_cpp/classes/input.hpp>

namespace godot {

class CaffeResult : public ViewModel {
	GDCLASS(CaffeResult, ViewModel)

protected:
    static void _bind_methods();

    NodePath main_info_path;
    NodePath result_path;

public:
    void set_main_info_path(NodePath p_main_info_path);
    NodePath get_main_info_path();
    void set_result_path(NodePath p_result_path);
    NodePath get_result_path();

    void set_main_info(String info);
    void set_result_info(String result);

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

};
}


#endif // CAFFE_RESULT_H
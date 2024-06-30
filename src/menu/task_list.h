#ifndef TASK_LIST_H
#define TASK_LIST_H
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/void_input.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/menu_element.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/progress_bar.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class TaskList : public MenuElement {
	GDCLASS(TaskList, MenuElement)

protected:
	static void _bind_methods();

public:
    void _set_menu() override;
	void _on_menu_opened() override;
	void _init_links() override;

	TaskList();
	~TaskList();
};

}

#endif //TASK_LIST_H
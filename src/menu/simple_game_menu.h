#ifndef SIMPLE_GAME_MENU_H
#define SIMPLE_GAME_MENU_H
#include <godot_cpp/classes/game_menu.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class SimpleGameMenu : public GameMenu {
	GDCLASS(SimpleGameMenu, GameMenu)

protected:
	static void _bind_methods();
    bool pause = false;

    Control *container = nullptr;
    NodePath container_path;

public:

    void _show_menu() override;
	void _hide_menu() override;
	void _int_process() override;
    void _init_elements() override;

    void set_container_path(NodePath p_container_path);
    NodePath get_container_path();

	SimpleGameMenu();
	~SimpleGameMenu();
};

}

#endif //SIMPLE_GAME_MENU_H
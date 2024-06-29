#ifndef STAT_MENU_H
#define STAT_MENU_H
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/void_input.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/menu_element.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class StatMenu : public MenuElement {
	GDCLASS(StatMenu, MenuElement)

protected:
	static void _bind_methods();

    Label *chill = nullptr;
    NodePath chill_path;

public:
    void _set_menu() override;
	void _on_menu_opened() override;
	void _init_links() override;

    void set_label(Label *label, EntityData *data, String name, String key);

    void set_chill_path(NodePath p_chill_path);
    NodePath get_chill_path();

	StatMenu();
	~StatMenu();
};

}

#endif //STAT_MENU_H
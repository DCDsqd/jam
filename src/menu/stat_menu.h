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
#include <godot_cpp/classes/progress_bar.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class StatMenu : public MenuElement {
	GDCLASS(StatMenu, MenuElement)

protected:
	static void _bind_methods();

    ProgressBar *happy = nullptr;
    ProgressBar *sleep = nullptr;
    ProgressBar *hunger = nullptr;

    Label *money = nullptr;
    Label *productive = nullptr;
    Label *effective = nullptr;
    Label *dream = nullptr;

    NodePath happy_path;
    NodePath sleep_path;
    NodePath hunger_path;

    NodePath money_path;
    NodePath productive_path;
    NodePath effective_path;
    NodePath dream_path;

public:
    void set_happy_path(NodePath p_happy_path);
    NodePath get_happy_path();

    void set_sleep_path(NodePath p_sleep_path);
    NodePath get_sleep_path();

    void set_hunger_path(NodePath p_huger_path);
    NodePath get_hunger_path();
    

    void set_money_path(NodePath p_money_path);
    NodePath get_money_path();

    void set_productive_path(NodePath p_productive_path);
    NodePath get_productive_path();
    
    void set_effective_path(NodePath p_effective_path);
    NodePath get_effective_path();

    void set_dream_path(NodePath p_dream_path);
    NodePath get_dream_path();


    void set_label(Label *label, EntityData *data, String name, String key);
    void set_progress_bar(ProgressBar *bar, EntityData *data, String name, String key);

    void _set_menu() override;
	void _on_menu_opened() override;
	void _init_links() override;

	StatMenu();
	~StatMenu();
};

}

#endif //STAT_MENU_H
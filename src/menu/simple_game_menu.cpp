#include "simple_game_menu.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::SimpleGameMenu::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_container_path"), &SimpleGameMenu::set_container_path);
	ClassDB::bind_method(D_METHOD("get_container_path"), &SimpleGameMenu::get_container_path);
	ClassDB::add_property("SimpleGameMenu", PropertyInfo(Variant::NODE_PATH, "container_path"), "set_container_path", "get_container_path");
}

void godot::SimpleGameMenu::_show_menu()
{
    if(this->container == nullptr){
        UtilityFunctions::print("SimpleGameMenu: container is null");
        return;
    }
    this->pause = true;
    this->container->set_visible(true);
    EternityData::get_singleton()->set_pause(true);
    
}

void godot::SimpleGameMenu::_hide_menu()
{
    if(this->container == nullptr){
        UtilityFunctions::print("SimpleGameMenu: container is null");
        return;
    }
    this->pause = false;
    this->container->set_visible(false);
    EternityData::get_singleton()->set_pause(false);
}

void godot::SimpleGameMenu::_int_process()
{
    if (EternityData::get_singleton()->get_lock()) {
        if (pause) {
            hide_menu();
        }
        return;
    }

    if (Input::get_singleton()->is_action_just_released("e_cancel")) {
        if (EternityData::get_singleton()->get_pause()) {
            hide_menu();
        } else {
            show_menu();
        }
    }
}

void godot::SimpleGameMenu::_init_elements()
{
    if(!has_node(container_path)){
        UtilityFunctions::print("SimpleGameMenu: container_path is null");
        return;
    }

    Control *p_container = get_node<Control>(container_path);

    if(p_container == nullptr){
        UtilityFunctions::print("SimpleGameMenu: container is incorrect");
        return;
    }

    this->container = p_container;
    if(p_container->is_visible()){
        show_menu();
    }
}

void godot::SimpleGameMenu::set_container_path(NodePath p_container_path)
{
    this->container_path = p_container_path;
}

godot::NodePath godot::SimpleGameMenu::get_container_path()
{
    return this->container_path;
}

godot::SimpleGameMenu::SimpleGameMenu()
{
}

godot::SimpleGameMenu::~SimpleGameMenu()
{
}

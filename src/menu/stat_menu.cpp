#include "stat_menu.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::StatMenu::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_chill_path"), &StatMenu::set_chill_path);
	ClassDB::bind_method(D_METHOD("get_chill_path"), &StatMenu::get_chill_path);
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "chill_path"), "set_chill_path", "get_chill_path");
}

void godot::StatMenu::_set_menu()
{

}

void godot::StatMenu::_on_menu_opened()
{
    Entity *entity = EternityData::get_singleton()->get_selected_entity();
    if(entity == nullptr){
        UtilityFunctions::print("StatMenu: selected entity is null");
        return;
    }

    if(entity->get_data() == nullptr){
        UtilityFunctions::print("StatMenu: data in entity is null");
        return;
    }

    set_label(chill, entity->get_data(), "Chill stat", HeroStats::chill());

}

void godot::StatMenu::_init_links()
{
    if(!has_node(chill_path)){
        UtilityFunctions::print("StatMenu: chill_path is null");
        return;
    }

    Label *p_chill = get_node<Label>(chill_path);
    if(!p_chill){
        UtilityFunctions::print("StatMenu: p_chill is incorect");
        return;
    }

    this->chill = p_chill;
}

void godot::StatMenu::set_label(Label *label, EntityData *data, String name, String key)
{
    if(label == nullptr){
        UtilityFunctions::print("StatMenu: label: " + name + "is null");
        return;
    }

    if(!data->has_float(key)){
        UtilityFunctions::print("StatMenu: data doesn't have key: " + key);
        return;
    }

    label->set_text(UtilityFunctions::var_to_str(data->get_float(key)));

}

void godot::StatMenu::set_chill_path(NodePath p_chill_path)
{
    this->chill_path = p_chill_path;
}

godot::NodePath godot::StatMenu::get_chill_path()
{
    return this->chill_path;
}

godot::StatMenu::StatMenu()
{
}

godot::StatMenu::~StatMenu()
{
}

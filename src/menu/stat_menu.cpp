#include "stat_menu.h"
#include "godot_cpp/variant/utility_functions.hpp"

namespace godot{



void godot::StatMenu::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_happy_path"), &StatMenu::set_happy_path);
	ClassDB::bind_method(D_METHOD("get_happy_path"), &StatMenu::get_happy_path);
    
    ClassDB::bind_method(D_METHOD("set_sleep_path"), &StatMenu::set_sleep_path);
	ClassDB::bind_method(D_METHOD("get_sleep_path"), &StatMenu::get_sleep_path);
    
    ClassDB::bind_method(D_METHOD("set_hunger_path"), &StatMenu::set_hunger_path);
	ClassDB::bind_method(D_METHOD("get_hunger_path"), &StatMenu::get_hunger_path);

    
    ClassDB::bind_method(D_METHOD("set_money_path"), &StatMenu::set_money_path);
	ClassDB::bind_method(D_METHOD("get_money_path"), &StatMenu::get_money_path);

	ClassDB::bind_method(D_METHOD("set_productive_path"), &StatMenu::set_productive_path);
	ClassDB::bind_method(D_METHOD("get_productive_path"), &StatMenu::get_productive_path);
    
	ClassDB::bind_method(D_METHOD("set_effective_path"), &StatMenu::set_effective_path);
	ClassDB::bind_method(D_METHOD("get_effective_path"), &StatMenu::get_effective_path);

	ClassDB::bind_method(D_METHOD("set_dream_path"), &StatMenu::set_dream_path);
	ClassDB::bind_method(D_METHOD("get_dream_path"), &StatMenu::get_dream_path);


	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "happy_path"), "set_happy_path", "get_happy_path");
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "sleep_path"), "set_sleep_path", "get_sleep_path");
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "hunger_path"), "set_hunger_path", "get_hunger_path");

	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "money_path"), "set_money_path", "get_money_path");
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "productive_path"), "set_productive_path", "get_productive_path");
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "effective_path"), "set_effective_path", "get_effective_path");
	ClassDB::add_property("StatMenu", PropertyInfo(Variant::NODE_PATH, "dream_path"), "set_dream_path", "get_dream_path");
}


void godot::StatMenu::set_happy_path(NodePath p_happy_path)
{
    this->happy_path = p_happy_path;
}

godot::NodePath godot::StatMenu::get_happy_path()
{
    return happy_path;
}

void StatMenu::set_sleep_path(NodePath p_sleep_path)
{
    this->sleep_path = p_sleep_path;
}

NodePath StatMenu::get_sleep_path()
{
    return this->sleep_path;
}

void StatMenu::set_hunger_path(NodePath p_huger_path)
{
    this->hunger_path = p_huger_path;
}

NodePath StatMenu::get_hunger_path()
{
    return this->hunger_path;
}

void StatMenu::set_money_path(NodePath p_money_path)
{
    this->money_path = p_money_path;
}

NodePath StatMenu::get_money_path()
{
    return this->money_path;
}

void StatMenu::set_productive_path(NodePath p_productive_path)
{
    this->productive_path = p_productive_path;
}

NodePath StatMenu::get_productive_path()
{
    return this->productive_path;
}

void StatMenu::set_effective_path(NodePath p_effective_path)
{
    this->effective_path = p_effective_path;
}

NodePath StatMenu::get_effective_path()
{
    return this->effective_path;
}

void StatMenu::set_dream_path(NodePath p_dream_path)
{
    this->dream_path = p_dream_path;
}

NodePath StatMenu::get_dream_path()
{
    return this->dream_path;
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

void StatMenu::set_progress_bar(ProgressBar *bar, EntityData *data, String name, String key)
{
    if(bar == nullptr){
        UtilityFunctions::print("StatMenu: progress_bar: " + name + "is null");
        return;
    }

    if(!data->has_float(key)){
        UtilityFunctions::print("StatMenu: data doesn't have key: " + key);
        return;
    }

    bar->set_max(1.0);
    bar->set_min(-1.0);
    bar->set_value(data->get_float(key));
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



    set_progress_bar(happy, entity->get_data(), "happy stat", HeroStats::happy());
    set_progress_bar(sleep, entity->get_data(), "sleep stat", HeroStats::sleep());
    set_progress_bar(hunger, entity->get_data(), "hunger stat", HeroStats::hunger());

    set_label(money, entity->get_data(), "money stat", HeroStats::money());
    set_label(productive, entity->get_data(), "productive stat", HeroStats::productive());
    set_label(effective, entity->get_data(), "effective stat", HeroStats::effective());
    set_label(dream, entity->get_data(), "dream stat", HeroStats::dream());

}

void godot::StatMenu::_init_links()
{
    if(has_node(happy_path) && get_node<ProgressBar>(happy_path)){
        this->happy = get_node<ProgressBar>(happy_path);
    }else{
        UtilityFunctions::print("StatMenu: happy_path is bad");
    }

    if(has_node(sleep_path) && get_node<ProgressBar>(sleep_path)){
        this->sleep = get_node<ProgressBar>(sleep_path);
    }else{
        UtilityFunctions::print("StatMenu: sleep_path is bad");
    }

    if(has_node(hunger_path) && get_node<ProgressBar>(hunger_path)){
        this->hunger = get_node<ProgressBar>(hunger_path);
    }else{
        UtilityFunctions::print("StatMenu: hunger_path is bad");
    }


    if(has_node(money_path) && get_node<Label>(money_path)){
        this->money = get_node<Label>(money_path);
    }else{
        UtilityFunctions::print("StatMenu: money_path is bad");
    }

    if(has_node(productive_path) && get_node<Label>(productive_path)){
        this->productive = get_node<Label>(productive_path);
    }else{
        UtilityFunctions::print("StatMenu: productive_path is bad");
    }
    
    if(has_node(effective_path) && get_node<Label>(effective_path)){
        this->effective = get_node<Label>(effective_path);
    }else{
        UtilityFunctions::print("StatMenu: productive_path is bad");
    }
    
    if(has_node(dream_path) && get_node<Label>(dream_path)){
        this->dream = get_node<Label>(dream_path);
    }else{
        UtilityFunctions::print("StatMenu: dream_path is bad");
    }
}


godot::StatMenu::StatMenu()
{
}

godot::StatMenu::~StatMenu()
{
}

}
#include "multi_selector_model.h"

#include "godot_cpp/variant/utility_functions.hpp"

void godot::MultiSelectorModel::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("add_interactor"), &MultiSelectorModel::add_interactor);
    ClassDB::bind_method(D_METHOD("set_offset"), &MultiSelectorModel::set_offset);
    ClassDB::bind_method(D_METHOD("select_option"), &MultiSelectorModel::select_option);
    ClassDB::bind_method(D_METHOD("set_start_pos"), &MultiSelectorModel::set_start_pos);
    ClassDB::bind_method(D_METHOD("get_start_pos"), &MultiSelectorModel::get_start_pos);

    ClassDB::add_property("MultiSelectorModel", PropertyInfo(Variant::NODE_PATH, "start_pos"), "set_start_pos", "get_start_pos");
}

void godot::MultiSelectorModel::add_interactor(String name, Interaction *interactor)
{
    interactors.push_back(Pair(name, interactor));
}

void godot::MultiSelectorModel::set_start_pos(NodePath p_start_pos_path)
{
    this->start_pos_path = p_start_pos_path;
}

godot::NodePath godot::MultiSelectorModel::get_start_pos()
{
    return this->start_pos_path;
}

void godot::MultiSelectorModel::set_offset(Vector2 p_offset)
{
    this->offset = p_offset;
}


void godot::MultiSelectorModel::select_option(int num)
{
    if(num >= interactors.size()){
        UtilityFunctions::print("MultiSelectorModel: num: " + UtilityFunctions::var_to_str(num) + "is to big");
        return;
    }

    interactors[num].second->interact(tmp_interactor);
    close_window();
}

void godot::MultiSelectorModel::_open_window(Entity *interaction, Entity *interactor)
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->lock_game();
    set_physics_process_internal(true);

    if(!has_node(start_pos_path)){
        UtilityFunctions::print("MultiSelectorModel: start_pos_path is null");
        return;
    }

    Control *marker = get_node<Control>(start_pos_path);

    if(marker == nullptr){
        UtilityFunctions::print("MultiSelectorModel: start_pos_path is not a control");
        return;
    }

    this->tmp_interaction = interaction;
    this->tmp_interactor = interactor;

    String value = Util::get_value_from_config("util", "selector_button");
    if(value == String())
        return;

    for(int i = 0; i < interactors.size(); ++i){
        interactors[i].second->set_entity(interaction);
        Node *node = Util::spawn_node(value);
        if(!node->cast_to<ParamButton>(node)){
            UtilityFunctions::print("MultiSelectorModel: not a param button");
            return;
        }
            
        ParamButton *button = node->cast_to<ParamButton>(node);
        add_child(button);
        button->set_position(marker->get_position() + offset*i);
        button->set_text(interactors[i].first);
        button->set_num(i);
        button->connect("param_activate", Callable(this, "select_option"));

    }

}

void godot::MultiSelectorModel::_close_window()
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->unlock_game();
}

void godot::MultiSelectorModel::_int_process()
{
    if(Input::get_singleton()->is_action_just_released("e_cancel")){
        close_window();
    }
}

godot::MultiSelectorModel::MultiSelectorModel()
{
}

godot::MultiSelectorModel::~MultiSelectorModel()
{
}

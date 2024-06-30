#include "view_model_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::ViewModelInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_view_model"), &ViewModelInteractor::set_view_model);
    ClassDB::bind_method(D_METHOD("set_sound_key"), &ViewModelInteractor::set_sound_key);
}

void godot::ViewModelInteractor::set_view_model(String p_model_path)
{
    this->model_path = p_model_path;
}

void godot::ViewModelInteractor::set_sound_key(String p_sound_key)
{
    this->sound_key = p_sound_key;
}

bool godot::ViewModelInteractor::_interact(Entity *p_entity)
{
    UtilityFunctions::print("ViewModelInteractor: interact with me");
    Node *node = Util::spawn_node(model_path);
    if(node == nullptr){
        UtilityFunctions::print("ViewModelInteractor: node is not created");
        return false;
    }

    ViewModel *model = Object::cast_to<ViewModel>(node);
    if(!model){
        UtilityFunctions::print("ViewModelInteractor: node is not a viewModel");
        return false;
    }

    Hud* hud = EternityData::get_singleton()->get_hud();

    if(hud == nullptr){
        UtilityFunctions::print("ViewModelInteractor: hud is null");
        return false;
    }
    hud->add_child(model);
    model->open_window(get_entity(), p_entity);

    if(sound_key != String())
        StaticMethods::play_sound(sound_key);

    return true;
}

godot::Interaction *godot::ViewModelInteractor::_clone()
{

    return new ViewModelInteractor();
}

godot::ViewModelInteractor::ViewModelInteractor()
{
    
}

godot::ViewModelInteractor::~ViewModelInteractor()
{
}

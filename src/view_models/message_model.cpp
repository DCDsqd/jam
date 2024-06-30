#include "message_model.h"
#include "godot_cpp/variant/utility_functions.hpp"


void godot::MessageModel::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_label_path"), &MessageModel::set_label_path);
    ClassDB::bind_method(D_METHOD("get_label_path"), &MessageModel::get_label_path);
    
    ClassDB::bind_method(D_METHOD("set_texture_path"), &MessageModel::set_texture_path);
    ClassDB::bind_method(D_METHOD("get_texture_path"), &MessageModel::get_texture_path);

    ClassDB::add_property("MessageModel", PropertyInfo(Variant::NODE_PATH, "label_path"), "set_label_path", "get_label_path");
    ClassDB::add_property("MessageModel", PropertyInfo(Variant::NODE_PATH, "texture_path"), "set_texture_path", "get_texture_path");
}

void godot::MessageModel::set_label_path(NodePath p_label_path)
{
    this->label_path = p_label_path;
}

godot::NodePath godot::MessageModel::get_label_path()
{
    return this->label_path;
}

void godot::MessageModel::set_texture_path(NodePath p_texture_path)
{
    this->texture_path = p_texture_path;
}

godot::NodePath godot::MessageModel::get_texture_path()
{
    return this->texture_path;
}

void godot::MessageModel::set_message(String message, int type)
{
    if(has_node(label_path) && get_node<Label>(label_path)){
        get_node<Label>(label_path)->set_text(message);
    }
    else{
        UtilityFunctions::print("MessageModel: texture not animatedTexture");
    }

    if(has_node(texture_path) && get_node<TextureRect>(texture_path) && get_node<TextureRect>(texture_path)->get_texture() != nullptr){
        if(get_node<TextureRect>(texture_path)->get_texture().ptr() && cast_to<AnimatedTexture>(get_node<TextureRect>(texture_path)->get_texture().ptr())){
            AnimatedTexture *texture = cast_to<AnimatedTexture>(get_node<TextureRect>(texture_path)->get_texture().ptr());
            texture->set_current_frame(type);
        }
        else{
            UtilityFunctions::print("MessageModel: texture not animatedTexture");
        }
    }
    else{
        UtilityFunctions::print("MessageModel: testure_rect so bad");
    }
}

void godot::MessageModel::_open_window(Entity *interaction, Entity *interactor)
{
    timer = 120.0f;
    set_physics_process_internal(true);
}

void godot::MessageModel::_close_window()
{
}

void godot::MessageModel::_int_process()
{
    if(timer -- <= 0.0f){
        close_window();
    }
}

godot::MessageModel::MessageModel()
{
}

godot::MessageModel::~MessageModel()
{
}

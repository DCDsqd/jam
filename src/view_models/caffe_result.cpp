#include "caffe_result.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::CaffeResult::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_main_info_path"), &CaffeResult::set_main_info_path);
	ClassDB::bind_method(D_METHOD("get_main_info_path"), &CaffeResult::get_main_info_path);
    
    ClassDB::bind_method(D_METHOD("set_result_path"), &CaffeResult::set_result_path);
	ClassDB::bind_method(D_METHOD("get_result_path"), &CaffeResult::get_result_path);

	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "main_info_path"), "set_main_info_path", "get_main_info_path");
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "result_path"), "set_result_path", "get_result_path");
}

void godot::CaffeResult::set_main_info_path(NodePath p_main_info_path)
{
    this->main_info_path = p_main_info_path;
}

godot::NodePath godot::CaffeResult::get_main_info_path()
{
    return this->main_info_path;
}

void godot::CaffeResult::set_result_path(NodePath p_result_path)
{
    this->result_path = p_result_path;
}

godot::NodePath godot::CaffeResult::get_result_path()
{
    return this->result_path;
}

void godot::CaffeResult::set_main_info(String info)
{
    if(!has_node(main_info_path)){
        UtilityFunctions::print("CaffeResult: main_info_path is null");
        return;
    }
    if(!get_node<RichTextLabel>(main_info_path)){
        UtilityFunctions::print("CaffeResult: main_info_path is incorrect");
        return;
    }
    
    get_node<RichTextLabel>(main_info_path)->set_text(info);
}

void godot::CaffeResult::set_result_info(String result)
{
    if(!has_node(result_path)){
        UtilityFunctions::print("CaffeResult: result_path is null");
        return;
    }
    if(!get_node<Label>(result_path)){
        UtilityFunctions::print("CaffeResult: result_path is incorrect");
        return;
    }
    
    get_node<Label>(result_path)->set_text(result);
}

void godot::CaffeResult::_open_window(Entity *interaction, Entity *interactor)
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->lock_game();
    set_physics_process_internal(true);
}

void godot::CaffeResult::_close_window()
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("SimpleViewModel: hud is null");
        return;
    }

    hud->unlock_game();
}

void godot::CaffeResult::_int_process()
{
    if(Input::get_singleton()->is_action_just_released("e_cancel")){
        close_window();
    }
}

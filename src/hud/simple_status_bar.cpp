#include "simple_status_bar.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::SimpleStatusBar::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_time_path"), &SimpleStatusBar::set_time_path);
    ClassDB::bind_method(D_METHOD("get_time_path"), &SimpleStatusBar::get_time_path);
    
    ClassDB::bind_method(D_METHOD("set_day_path"), &SimpleStatusBar::set_day_path);
    ClassDB::bind_method(D_METHOD("get_day_path"), &SimpleStatusBar::get_day_path);

    ClassDB::add_property("SimpleStatusBar", PropertyInfo(Variant::NODE_PATH, "time_path"), "set_time_path", "get_time_path");
    ClassDB::add_property("SimpleStatusBar", PropertyInfo(Variant::NODE_PATH, "day_path"), "set_day_path", "get_day_path");
}

godot::String godot::SimpleStatusBar::get_day(int cur_day)
{
    if(cur_day == 0){
        return Util::get_value_from_config("word", "day_0");
    }else if (cur_day == 1){
        return Util::get_value_from_config("word", "day_1");
    }else if (cur_day == 2){
        return Util::get_value_from_config("word", "day_2");
    }else if (cur_day == 3){
        return Util::get_value_from_config("word", "day_3");
    }else{
        return Util::get_value_from_config("word", "day_4");
    }
}

void godot::SimpleStatusBar::set_time(int cur_time)
{
    if(!(get_node<TextureRect>(time_path)->get_texture().ptr() && cast_to<AnimatedTexture>(get_node<TextureRect>(time_path)->get_texture().ptr()))){
        UtilityFunctions::print("SimpleStatusBar: texture not animatedTexture");
        return;
    }
    AnimatedTexture *texture = cast_to<AnimatedTexture>(get_node<TextureRect>(time_path)->get_texture().ptr());
    texture->set_current_frame(cur_time);
}

void godot::SimpleStatusBar::set_time_path(NodePath p_time_path)
{
    this->time_path = p_time_path;
}

godot::NodePath godot::SimpleStatusBar::get_time_path()
{
    return this->time_path;
}

void godot::SimpleStatusBar::set_day_path(NodePath p_day_path)
{
    this->day_path = p_day_path;
}

godot::NodePath godot::SimpleStatusBar::get_day_path()
{
    return this->day_path;
}

void godot::SimpleStatusBar::_update_info()
{
    if(this->day == nullptr || this->time == nullptr){
        UtilityFunctions::print("SimpleStatusBar: ptr day or ptr time is null");
        return;
    }

    if(EternityData::get_singleton()->get_controller() == nullptr){
        UtilityFunctions::print("SimpleStatusBar: controller is null");
        return;
    }

    GameController *controller = EternityData::get_singleton()->get_controller();

    if(!controller->has_int("game_day") || !controller->has_int("game_time")){
        UtilityFunctions::print("SimpleStatusBar: game_day or game_time is null ");
        return;
    }

    this->day->set_text(get_day(controller->get_int("game_day")));
    set_time(controller->get_int("game_time"));
    //this->time->set_text(UtilityFunctions::var_to_str(controller->get_int("game_time")));

}

void godot::SimpleStatusBar::_init_links()
{
    if(has_node(day_path) && get_node<Label>(day_path)){
        day = get_node<Label>(day_path);
    }
    else{
        UtilityFunctions::print("SimpleStatusBar: day bad link");
    }

    if(has_node(time_path) && get_node<TextureRect>(time_path)){
        if(get_node<TextureRect>(time_path)->get_texture().ptr() && cast_to<AnimatedTexture>(get_node<TextureRect>(time_path)->get_texture().ptr())){
            time = get_node<TextureRect>(time_path);
        }
        else{
            UtilityFunctions::print("SimpleStatusBar: texture not animatedTexture");
        }
    }
    else{
        UtilityFunctions::print("SimpleStatusBar: time bad link");
    }
    update_info();
}

godot::SimpleStatusBar::SimpleStatusBar()
{
}

godot::SimpleStatusBar::~SimpleStatusBar()
{
}


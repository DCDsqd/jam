#include "bubble_spr.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::BubbleSpr::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_max_time"), &BubbleSpr::set_max_time);
    ClassDB::bind_method(D_METHOD("set_speed"), &BubbleSpr::set_speed);
    ClassDB::bind_method(D_METHOD("set_dir"), &BubbleSpr::set_dir);
}

void godot::BubbleSpr::set_max_time(float p_max_time)
{
    this->max_time = p_max_time;
}

void godot::BubbleSpr::set_speed(float p_speed)
{
    this->speed = p_speed;
}

void godot::BubbleSpr::set_dir(Vector3 p_dir)
{
    this->dir = p_dir;
}


void godot::BubbleSpr::set_sprite(String path)
{
    Ref<Texture2D> spr = Util::load_image(path);

    if(spr == Ref<Texture2D>()){
        UtilityFunctions::print("BubbleSpr: spr is null");
        return;
    }

    this->set_texture(spr);
}

void godot::BubbleSpr::_physics_process(float delta)
{
    if(!Engine::get_singleton()->is_editor_hint()){
        if(timer ++ >= max_time){
            queue_free();
        }
        set_position(get_position()+dir*speed);
    }
}

godot::BubbleSpr::BubbleSpr()
{
}

godot::BubbleSpr::~BubbleSpr()
{
}

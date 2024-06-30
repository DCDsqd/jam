#include "cafe_put_order_interactor.h"
#include "util/caffe_controller.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/hero_stats.hpp"

void godot::CafePutOrderInteractor::_bind_methods()
{
}

void godot::CafePutOrderInteractor::spawn_cloud(String name)
{
    String value = Util::get_value_from_config("util", "bubble_spr");
    if(value == String())
        return;

    Node *node = Util::spawn_node(value);
    if(!node->cast_to<BubbleSpr>(node)){
        UtilityFunctions::print("CaffeController: not a bubble_spr");
        return;
    }
        
    BubbleSpr *bubble = node->cast_to<BubbleSpr>(node);
    controller->add_child(bubble);
    bubble->set_position(get_pos() + Vector3(0.0f, 1.5f, 0.0f));
    bubble->set_scale(Vector3(2.0f, 2.0f, 2.0f));
    bubble->set_sprite(name);
}

void godot::CafePutOrderInteractor::set_controller(CaffeController *p_controller)
{
    this->controller = p_controller;
}

void godot::CafePutOrderInteractor::set_order_name(String p_order_name)
{
    this->order_name = p_order_name;
}

void godot::CafePutOrderInteractor::set_pos(Vector3 p_pos)
{
    this->pos = p_pos;
}

godot::String godot::CafePutOrderInteractor::get_order_name()
{
    return this->order_name;
}

godot::Vector3 godot::CafePutOrderInteractor::get_pos()
{
    return this->pos;
}

bool godot::CafePutOrderInteractor::_interact(Entity *p_entity)
{
    if(p_entity == nullptr){
        UtilityFunctions::print("CafePutOrderInteractor: p_entity is null");
        return false;
    }

    if(p_entity->get_data() == nullptr){
        UtilityFunctions::print("CafePutOrderInteractor: data is null");
        return false;
    }

    EntityData *data = p_entity->get_data();

    if(!data->has_string(HeroStats::cafe_order())){
        UtilityFunctions::print("CafePutOrderInteractor: data doesn't have order");
        return false;
    }

    if(data->get_string(HeroStats::cafe_order()) == order_name){
        UtilityFunctions::print("CafePutOrderInteractor: oreder has get");
        spawn_cloud(Util::get_value_from_config("util", "correct_cloud"));
        data->put_string(HeroStats::cafe_order(), "");
        controller->add_progress();
        return true;
    }
    
    UtilityFunctions::print("CafePutOrderInteractor: order is incorect");
    spawn_cloud(Util::get_value_from_config("util", "bad_cloud"));
    controller->plus_score(-1);
    return false;
}

godot::Interaction *godot::CafePutOrderInteractor::_clone()
{
    return new CafePutOrderInteractor();
}

godot::CafePutOrderInteractor::CafePutOrderInteractor()
{
    UtilityFunctions::print("CafePutOrderInteractor: spawned");
}

godot::CafePutOrderInteractor::~CafePutOrderInteractor()
{
}

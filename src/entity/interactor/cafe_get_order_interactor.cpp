#include "cafe_get_order_interactor.h"
#include "util/caffe_controller.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/hero_stats.hpp"

void godot::CafeGetOrderInteractor::_bind_methods()
{
}

void godot::CafeGetOrderInteractor::spawn_cloud(String name)
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

void godot::CafeGetOrderInteractor::set_order_name(String p_order_name)
{
    this->order_name = p_order_name;
}


void godot::CafeGetOrderInteractor::set_has_order(bool p_has_order)
{
    this->has_order = p_has_order;
}

void godot::CafeGetOrderInteractor::set_pos(Vector3 p_pos)
{
    this->pos = p_pos;
}

void godot::CafeGetOrderInteractor::set_controller(CaffeController *p_controller)
{
    this->controller = p_controller;
}

godot::String godot::CafeGetOrderInteractor::get_order_name()
{
    return this->order_name;
}

godot::Vector3 godot::CafeGetOrderInteractor::get_pos()
{
    return this->pos;
}

bool godot::CafeGetOrderInteractor::_interact(Entity *p_entity)
{
    if(!has_order){
        return false;
    }
    
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
        data->put_string(HeroStats::cafe_order(), order_name);
        has_order = false;
        spawn_cloud(Util::get_value_from_config("util", "correct_cloud"));
        return true;
    }

    if(data->get_string(HeroStats::cafe_order()) != ""){
        UtilityFunctions::print("CafePutOrderInteractor: cafe order not empty");
        spawn_cloud(Util::get_value_from_config("util", "bad_cloud"));
        return false;
    }
    
    data->put_string(HeroStats::cafe_order(), order_name);
    has_order = false;
    spawn_cloud(Util::get_value_from_config("util", "correct_cloud"));
    return true;
}

godot::Interaction *godot::CafeGetOrderInteractor::_clone()
{
    
    return memnew(CafeGetOrderInteractor);
}

godot::CafeGetOrderInteractor::CafeGetOrderInteractor()
{
}

godot::CafeGetOrderInteractor::~CafeGetOrderInteractor()
{
}

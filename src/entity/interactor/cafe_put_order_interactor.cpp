#include "cafe_put_order_interactor.h"
#include "util/caffe_controller.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/hero_stats.hpp"

void godot::CafePutOrderInteractor::_bind_methods()
{
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
        data->put_string(HeroStats::cafe_order(), "");
        controller->add_progress();
        return true;
    }
    
    UtilityFunctions::print("CafePutOrderInteractor: order is incorect");
    controller->plus_score(-0.5f);
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

#include "parametr_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::ParametrInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_sound_key"), &ParametrInteractor::set_sound_key);

    ClassDB::bind_method(D_METHOD("set_add_day"), &ParametrInteractor::set_add_day);

    ClassDB::bind_method(D_METHOD("check_param_entity"), &ParametrInteractor::check_param_entity);
    ClassDB::bind_method(D_METHOD("check_param_controller"), &ParametrInteractor::check_param_controller);
    ClassDB::bind_method(D_METHOD("plus_param_entity"), &ParametrInteractor::plus_param_entity);
    ClassDB::bind_method(D_METHOD("plus_param_controller"), &ParametrInteractor::plus_param_controller);
}

bool godot::ParametrInteractor::check_valide(Entity *p_entity)
{
    if(p_entity == nullptr){
        UtilityFunctions::print("ParametrInteractor: entity is null");
        return false;
    }

    if(p_entity->get_data() == nullptr){
        UtilityFunctions::print("ParametrInteractor: entity data is null");
        return false;
    }

    if(EternityData::get_singleton()->get_controller() == nullptr){
        UtilityFunctions::print("ParametrInteractor: controller is null");
        return false;
    }

    return true;
}

bool godot::ParametrInteractor::check_value(Entity *p_entity)
{
    GameController *controller = EternityData::get_singleton()->get_controller();

    for(auto i : map_check_param_controller){
        if(!controller->has_int(i.key)){
            UtilityFunctions::print("ParametrInteractor: controller not have int: ", i.key);
            return false;
        }
        if(controller->get_int(i.key) < i.value){
            UtilityFunctions::print("ParametrInteractor: controller int so low: ", controller->get_int(i.key), " needed: ", i.value);
            return false;
        }
    }

    EntityData *data = p_entity->get_data();
    for(auto i : map_check_param_entity){
        if(!data->has_float(i.key)){
            UtilityFunctions::print("ParametrInteractor: data not have float: ", i.key);
            return false;
        }
        if(data->get_float(i.key) < i.value){
            UtilityFunctions::print("ParametrInteractor: data float so low: ", data->get_float(i.key), " needed: ", i.value);
            return false;
        }
    }

    return true;
}

void godot::ParametrInteractor::set_value(Entity *p_entity)
{
    GameController *controller = EternityData::get_singleton()->get_controller();

    for(auto i : map_plus_param_controller){
        if(!controller->has_int(i.key)){
            UtilityFunctions::print("ParametrInteractor: controller not have int: ", i.key, ". insert");
            controller->put_int(i.key, i.value);
        }
        int tmp = controller->get_int(i.key);
        controller->put_int(i.key, tmp + i.value);
    }

    EntityData *data = p_entity->get_data();
    for(auto i : map_plus_param_entity){
        if(!data->has_float(i.key)){
            UtilityFunctions::print("ParametrInteractor: data not have float: ", i.key, ". insert");
            
        }
        float tmp = data->get_float(i.key);
        data->put_float(i.key, tmp + i.value);
    }

}

void godot::ParametrInteractor::set_sound_key(String p_sound_key)
{
    this->sound_key = p_sound_key;
}

void godot::ParametrInteractor::check_param_entity(String key, float value)
{
    this->map_check_param_entity[key] = value;
}

void godot::ParametrInteractor::check_param_controller(String key, int value)
{
    this->map_check_param_controller[key] = value;
}

void godot::ParametrInteractor::plus_param_entity(String key, float value)
{
    this->map_plus_param_entity[key] = value;
}

void godot::ParametrInteractor::plus_param_controller(String key, int value)
{
    this->map_plus_param_controller[key] = value;
}

void godot::ParametrInteractor::set_add_day(bool p_add_day)
{
    this->add_day = p_add_day;
}

bool godot::ParametrInteractor::_interact(Entity *p_entity)
{
    
    if(!check_valide(p_entity))
        return false;
    
    UtilityFunctions::print("ParametrInteractor: start interact");
    if(check_value(p_entity)){
        set_value(p_entity);

        if(add_day)
            StaticMethods::add_time();

        if(sound_key != String())
            StaticMethods::play_sound(sound_key);

        return true;
    }

    return true;
}

godot::Interaction *godot::ParametrInteractor::_clone()
{
    return memnew(ParametrInteractor);
}

godot::ParametrInteractor::ParametrInteractor()
{
}

godot::ParametrInteractor::~ParametrInteractor()
{
}

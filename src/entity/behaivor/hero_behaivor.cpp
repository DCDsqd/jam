#include "hero_behaivor.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::HeroBehaivor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("calculate_stats"), &HeroBehaivor::calculate_stats);
}

void godot::HeroBehaivor::_set_entity(ModelEntity *p_entity)
{
    if(p_entity != nullptr && p_entity->get_entity() != nullptr)
        p_entity->get_entity()->connect("on_buffs_change", Callable(this, "calculate_stats"));
    else
        UtilityFunctions::print("HeroBehaivor: entity in mentity is null");

    calculate_stats();
}

void godot::HeroBehaivor::_int_process()
{
}

void godot::HeroBehaivor::calculate_stats()
{
    ModelEntity* mentity = get_entity();
    if(mentity == nullptr){
        UtilityFunctions::print("HeroBehaivor: mentity is null");
        return;
    }
    Entity* entity = mentity->get_entity();

    if(entity == nullptr){
        UtilityFunctions::print("HeroBehaivor: entity is null");
        return;
    }

    EntityData *data = entity->get_data();
    if(data == nullptr){
        UtilityFunctions::print("HeroBehaivor: data is null");
        return;
    }

    UtilityFunctions::print("HeroBehaivor: calculate new values");

    float prod = 0.0f;
    if(data->has_float(HeroStats::chill())){
        float chill = data->get_float(HeroStats::chill());
        UtilityFunctions::print("HeroBehaivor: chill value: " + UtilityFunctions::var_to_str(chill));
        if(chill > 8.0f){
            prod += 0.25f;
        }
        else{
            prod -= 0.25f;
        }
    }

    data->put_float(HeroStats::productive(), prod);
    UtilityFunctions::print("HeroBehaivor: prod value: " + UtilityFunctions::var_to_str(prod));

    
}

godot::HeroBehaivor::HeroBehaivor()
{
}

godot::HeroBehaivor::~HeroBehaivor()
{
}

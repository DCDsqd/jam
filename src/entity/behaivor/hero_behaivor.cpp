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

    float effective = 1.0f;
    float productive = 1.0f;
    float dream = 1.0f;
    
    if(data->has_float(HeroStats::sleep())){
        float sleep = data->get_float(HeroStats::sleep());
        if(sleep < -0.25f){
            effective -= 0.25f;

            if(sleep < -0.5f)
                effective -= 0.25f;
        }
        if(sleep > 0.25f){
            productive += 0.25f;
        }
    }

    if(data->has_float(HeroStats::happy())){
        float happy = data->get_float(HeroStats::happy());
        if(happy < -0.25f){
            productive -= 0.25f;

            if(happy < -0.5f)
                effective -= 0.25f;
        }
        if(happy > 0.25f){
            effective += 0.25f;
        }
    }

    if(data->has_float(HeroStats::hunger())){
        float hunger = data->get_float(HeroStats::hunger());
        if(hunger < -0.25f){
            productive -= 0.25f;

            if(hunger < -0.5f)
                effective -= 0.25f;
        }
        if(hunger > 0.25f){
            effective += 0.25f;
        }
    }

    data->put_float(HeroStats::effective(), effective);
    data->put_float(HeroStats::productive(), productive);
    data->put_float(HeroStats::dream(), dream);

}

godot::HeroBehaivor::HeroBehaivor()
{
}

godot::HeroBehaivor::~HeroBehaivor()
{
}

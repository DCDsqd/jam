#include "hero_behaivor.h"

void godot::HeroBehaivor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("calculate_stats"), &HeroBehaivor::calculate_stats);
}

void godot::HeroBehaivor::_set_entity(Entity *p_entity)
{
    p_entity->connect("buff_change", Callable(this, "calculate_stats"));
    calculate_stats();
}

void godot::HeroBehaivor::_int_process()
{
}

godot::VoidBehaivor *godot::HeroBehaivor::_clone()
{
    return new HeroBehaivor();
}

void godot::HeroBehaivor::calculate_stats()
{
    Entity* entity = get_entity();
    if(entity == nullptr){
        return;
    }

    EntityData *data = entity->get_data();
    if(data == nullptr){
        return;
    }

    
}

godot::HeroBehaivor::HeroBehaivor()
{
}

godot::HeroBehaivor::~HeroBehaivor()
{
}

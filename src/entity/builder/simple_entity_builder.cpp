#include "simple_entity_builder.h"
#include "variants/entity_params.hpp"
#include "variants/hero_stats.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::SimpleEntityBuilder::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_jump_timer"), &SimpleEntityBuilder::set_jump_timer);
    ClassDB::bind_method(D_METHOD("set_speed"), &SimpleEntityBuilder::set_speed);
    ClassDB::bind_method(D_METHOD("set_jump_str"), &SimpleEntityBuilder::set_jump_str);
    ClassDB::bind_method(D_METHOD("set_gravity"), &SimpleEntityBuilder::set_gravity);
    ClassDB::bind_method(D_METHOD("set_coyot_timer"), &SimpleEntityBuilder::set_coyot_timer);
    ClassDB::bind_method(D_METHOD("set_jump_save_timer"), &SimpleEntityBuilder::set_jump_save_timer);
    ClassDB::bind_method(D_METHOD("set_friction"), &SimpleEntityBuilder::set_friction);
    ClassDB::bind_method(D_METHOD("set_velocity"), &SimpleEntityBuilder::set_velocity);

    ClassDB::bind_method(D_METHOD("set_stats"), &SimpleEntityBuilder::set_stats);

    ClassDB::bind_method(D_METHOD("set_move_sound_modifier"), &SimpleEntityBuilder::set_move_sound_modifier);
}

void godot::SimpleEntityBuilder::set_jump_timer(float p_jumpt_timer)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::JUMP_TIMER(), p_jumpt_timer);
}

void godot::SimpleEntityBuilder::set_speed(float p_speed)
{
    UtilityFunctions::print(EntityParams::SPEED());
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::SPEED(), p_speed);
}

void godot::SimpleEntityBuilder::set_jump_str(float p_jump_str)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::JUMP_STR(), p_jump_str);
}

void godot::SimpleEntityBuilder::set_gravity(float p_gravity)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::GRAVITY(), p_gravity);
}

void godot::SimpleEntityBuilder::set_coyot_timer(float p_coyot_timer)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::COYOT_TIMER(), p_coyot_timer);
}

void godot::SimpleEntityBuilder::set_jump_save_timer(float p_jump_save_timer)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::JUMP_SAVE_TIMER(), p_jump_save_timer);
}

void godot::SimpleEntityBuilder::set_velocity(float p_velocity)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::VELOCITY(), p_velocity);
}

void godot::SimpleEntityBuilder::set_friction(float p_friction)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_float(EntityParams::FRICTION(), p_friction);
}

void godot::SimpleEntityBuilder::set_stats()
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }
    get_data()->put_string(HeroStats::cafe_order(), "");

    get_data()->put_float(HeroStats::money(), 500.0);
    get_data()->put_float(HeroStats::productive(), 1.0);
    get_data()->put_float(HeroStats::effective(), 1.0);
    get_data()->put_float(HeroStats::dream(), 1.0);

    get_data()->put_float(HeroStats::happy(), 0.0);
    get_data()->put_float(HeroStats::sleep(), 0.0);
    get_data()->put_float(HeroStats::hunger(), 0.0);
}

void godot::SimpleEntityBuilder::set_move_sound_modifier(float p_step_sound_modifier)
{
    if(get_data() == nullptr){
        UtilityFunctions::print("SimpleEntityBuilder: data is null");
        return;
    }

    get_data()->put_float(EntityParams::step_sound_modifier(), p_step_sound_modifier);
}

godot::SimpleEntityBuilder::SimpleEntityBuilder()
{
}

godot::SimpleEntityBuilder::~SimpleEntityBuilder()
{
}

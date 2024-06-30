#include "platformer_mover_3d.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/entity_params.hpp"

void godot::PlatformerMover3D::_bind_methods()
{
}

void godot::PlatformerMover3D::_set_entity()
{
	is_data_change();
}

void godot::PlatformerMover3D::_move(const Vector3 &move_dir, bool jmp)
{
    MovingEntity *entity = get_entity();
	Vector3 velocity = entity->get_velocity();

	if(entity->is_on_floor()){
		on_floor_move(velocity, move_dir, jmp);
	}else{
		on_air_move(velocity, move_dir, jmp);
	}

}

void godot::PlatformerMover3D::_is_data_change()
{
	UtilityFunctions::print("PlatformerMover3D: change data");
    EntityData *data = get_data();

    if (data == nullptr) {
		return;
	}

	if (data->has_float(EntityParams::SPEED())) {
		params->speed = data->get_float(EntityParams::SPEED());
	}

	if (data->has_float(EntityParams::JUMP_STR())) {
		params->jump_str = data->get_float(EntityParams::JUMP_STR());
	}

	if (data->has_float(EntityParams::GRAVITY())) {
		params->gravity = data->get_float(EntityParams::GRAVITY());
	}

	if (data->has_float(EntityParams::JUMP_TIMER())) {
		params->jump_timer = data->get_float(EntityParams::JUMP_TIMER());
	}

	if (data->has_float(EntityParams::COYOT_TIMER())) {
		params->coyot_timer = data->get_float(EntityParams::COYOT_TIMER());
	}

	if (data->has_float(EntityParams::JUMP_SAVE_TIMER())) {
		params->jump_save_timer = data->get_float(EntityParams::JUMP_SAVE_TIMER());
	}

	if (data->has_float(EntityParams::VELOCITY())) {
		params->velocity = data->get_float(EntityParams::VELOCITY());
	}

	if (data->has_float(EntityParams::FRICTION())) {
		params->friction = data->get_float(EntityParams::FRICTION());
	} 

	if (data->has_float(EntityParams::step_sound_modifier())) {
		params->step_sound_modifier = data->get_float(EntityParams::step_sound_modifier());
	} 
}

void godot::PlatformerMover3D::on_floor_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
	coyot = params->coyot_timer;
	step_sound_cd -= 0.1f;

	Vector2 ground_velocity = Vector2(velocity.x, velocity.z);
	Vector2 friction_vector = ground_velocity.normalized() * params->friction;
	
	velocity.x -= friction_vector.x;
	velocity.z -= friction_vector.y;

	velocity.y -= params->gravity;
	velocity.x += move_dir.x * params->velocity;
	velocity.z = 0;

	get_entity()->set_animator_rotation(move_dir);

	ground_velocity = Vector2(velocity.x, velocity.z);

	if(ground_velocity.abs().length() > params->velocity){
		if(step_sound_cd <= 0.0f){
			//get_entity()->animator_play_sound("step");
			this->step_sound_cd = (1/(ground_velocity.abs().length()+1))*params->step_sound_modifier;
		}

		if(move_dir.abs().length() > 0.0f){
			get_entity()->animate(EntityParams::run_anim(), ground_velocity.abs().length()/100.0f);
		}
		else{
			get_entity()->animate(EntityParams::idle_anim(), 1.0f);
		}
	}
	else{
		get_entity()->animate(EntityParams::idle_anim(), 1.0f);
	}

	if(ground_velocity.abs().length() > params->speed){
		ground_velocity = ground_velocity.normalized() * params->speed;
		velocity.x = ground_velocity.x;
		velocity.z = ground_velocity.y;
	}

	if(jmp){
		velocity.y += params->jump_str;
		jump_tmp = params->jump_timer;
	}

	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

void godot::PlatformerMover3D::on_air_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
	if(coyot > 0.0f){
		coyot -= 0.1f;
	}

	velocity.y -= params->gravity;
	velocity.x += move_dir.x * params->velocity;
	velocity.z += move_dir.z * params->velocity;

	Vector2 ground_velocity = Vector2(velocity.x, velocity.z);
	if(ground_velocity.abs().length() > params->speed){
		ground_velocity = ground_velocity.normalized() * params->speed;
		velocity.x = ground_velocity.x;
		velocity.z = ground_velocity.y;
	}

	if(velocity.y > 0){
		on_fly_move(velocity, move_dir, jmp);
	}else{
		on_fall_move(velocity, move_dir, jmp);
	}

	
}

void godot::PlatformerMover3D::on_fly_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
	if(jump_tmp > 0.0f){
		if(jmp){
			velocity.y += params->jump_str*((float)params->jump_timer/(float)jump_tmp);
			jump_tmp -= 0.1f;
		}
		else
			jump_tmp = 0.0f;
	}

	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

void godot::PlatformerMover3D::on_fall_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
	if(coyot > 0.0f && jmp){
		velocity.y = -velocity.y + params->jump_str;
		jump_tmp = params->jump_save_timer;
		coyot = 0.0f;
	}

	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

godot::PlatformerMover3D::PlatformerMover3D()
{
}

godot::PlatformerMover3D::~PlatformerMover3D()
{
}

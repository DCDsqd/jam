#include "dino_mover.h"

void godot::DinoMover::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_gravity"), &DinoMover::set_gravity);
    ClassDB::bind_method(D_METHOD("set_jump_str"), &DinoMover::set_jump_str);
    ClassDB::bind_method(D_METHOD("set_jump_timer"), &DinoMover::set_jump_timer);
}

void godot::DinoMover::_set_entity()
{
}

void godot::DinoMover::_move(const Vector3 &move_dir, bool jmp)
{
    MovingEntity *entity = get_entity();
    Vector3 velocity = entity->get_velocity();

	if(entity->is_on_floor()){
		on_floor_move(velocity, move_dir, jmp);
	}else{
		on_air_move(velocity, move_dir, jmp);
	}
}

void godot::DinoMover::_is_data_change()
{
}

void godot::DinoMover::set_gravity(float p_gravity)
{
    this->gravity = p_gravity;
}

void godot::DinoMover::set_jump_str(float p_jump_str)
{
    this->jump_str = p_jump_str;
}

void godot::DinoMover::set_jump_timer(float p_jump_timer)
{
    this->jump_timer = p_jump_timer;
    jump_tmp = jump_timer;
}

void godot::DinoMover::on_floor_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
    velocity.y -= gravity;

	get_entity()->set_animator_rotation(move_dir);


	if(jmp){
		velocity.y += jump_str;
		jump_tmp = jump_timer;
	}

	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

void godot::DinoMover::on_air_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{

	velocity.y -= gravity;

	if(velocity.y > 0){
		on_fly_move(velocity, move_dir, jmp);
	}else{
		on_fall_move(velocity, move_dir, jmp);
	}
}

void godot::DinoMover::on_fly_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
    if(jump_tmp > 0.0f){
		if(jmp){
			velocity.y += jump_str*((float)jump_timer/(float)jump_tmp);
			jump_tmp -= 0.1f;
		}
		else
			jump_tmp = 0.0f;
	}

	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

void godot::DinoMover::on_fall_move(Vector3 velocity, const Vector3 &move_dir, bool jmp)
{
	get_entity()->set_velocity(velocity);
	get_entity()->move_and_slide();
}

godot::DinoMover::DinoMover()
{
}

godot::DinoMover::~DinoMover()
{
}

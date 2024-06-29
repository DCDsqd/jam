#ifndef PLATFORMER_MOVER_3D_H
#define PLATFORMER_MOVER_3D_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>

namespace godot {

class PlatformerParams{
public:
    double time_passed;
	float jump_timer = 10.0f;
	float speed = 10.0f;
	float jump_str = 10.0f;
	float gravity = 9.0f;
	float friction = 0.2f;
	float velocity = 0.5f;

    float coyot_timer = 10.0f;
    float jump_save_timer = 0.0f;

	float step_sound_modifier = 0.01f;
};

class PlatformerMover3D : public MoveComponent {
	GDCLASS(PlatformerMover3D, MoveComponent)

private:
	PlatformerParams *params = new PlatformerParams();
	float step_sound_cd = 0.0f;

	float coyot = 0.0f;
	float jump_saver = 0.0f;
	float jump_tmp = 0.0f;

protected:
	static void _bind_methods();

public:
	void _set_entity() override;
	void _move(const Vector3 &move_dir, bool jmp) override;
	void _is_data_change() override;

	void on_floor_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);
	void on_air_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);

	void on_fly_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);
	void on_fall_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);

	PlatformerMover3D();
	~PlatformerMover3D();
};

}

#endif //PLATFORMER_MOVER_3D_H
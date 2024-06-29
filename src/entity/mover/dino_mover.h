#ifndef DINO_MOVER_H
#define DINO_MOVER_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>

namespace godot {

class DinoMover : public MoveComponent {
	GDCLASS(DinoMover, MoveComponent)


protected:
	static void _bind_methods();
    float gravity = 0.5f;
    float jump_str = 1.0f;
    float jump_timer = 2.0f;
    float jump_tmp = jump_timer;

public:
	void _set_entity() override;
	void _move(const Vector3 &move_dir, bool jmp) override;
	void _is_data_change() override;

    void set_gravity(float p_gravity);
    void set_jump_str(float p_jump_str);
    void set_jump_timer(float p_jump_timer);

    void on_floor_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);
    void on_air_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);

    void on_fly_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);
	void on_fall_move(Vector3 velocity, const Vector3 &move_dir, bool jmp);


	DinoMover();
	~DinoMover();


};

}

#endif //DINO_MOVER_H
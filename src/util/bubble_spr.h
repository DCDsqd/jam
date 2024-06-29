#ifndef BUBBLE_SPR_H
#define BUBBLE_SPR_H

#include <godot_cpp/classes/sprite3d.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/texture2d.hpp>

namespace godot {

class BubbleSpr : public Sprite3D {
	GDCLASS(BubbleSpr, Sprite3D)

protected:
	static void _bind_methods();

	float max_time = 0.0f;
	float timer = 0.0f;
	Vector3 dir = Vector3(0.0f, 0.0f, 0.0f);

	float speed = 0.0f;

public:
	void set_max_time(float p_max_time);
	void set_speed(float p_speed);
	void set_dir(Vector3 p_dir);

	void set_sprite(String path);

	void _physics_process(float delta);

	BubbleSpr();
	~BubbleSpr();
};

}

#endif //BUBBLE_SPR_H
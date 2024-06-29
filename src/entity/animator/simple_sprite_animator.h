#ifndef SIMPLE_SPRITE_ANIMATOR_H
#define SIMPLE_SPRITE_ANIMATOR_H

#include <godot_cpp/classes/animator.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/model.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/json.hpp>
#include <godot_cpp/classes/audio_stream_player3d.hpp>

namespace godot {

class SimpleSpriteAnimator : public Animator {
	GDCLASS(SimpleSpriteAnimator, Animator)

private:
	//Ref<AudioStream> sound;
	HashMap<String, Ref<AudioStream>> bind_map;
	void parse_audio_map(Dictionary map);

protected:
	static void _bind_methods();

public:
	void _set_animation(const String &animation, int32_t speed) override;
	int32_t _has_animation() override;
	void _set_rotation(const Vector3 &rot) override;
	Vector3 _get_rotation() override;
	void _play_sound(const String &arg_1) override;

	void set_audio_map(HashMap<String, Ref<AudioStream>> p_bind_map);
	void parse_from_json(String path);

	SimpleSpriteAnimator();
	~SimpleSpriteAnimator();
};

}

#endif //SIMPLE_SPRITE_ANIMATOR_H
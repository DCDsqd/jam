#ifndef TRIGGER_MUSIC_H
#define TRIGGER_MUSIC_H


#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/music_controller.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>


namespace godot {

class TriggerMusic : public Trigger3D {
	GDCLASS(TriggerMusic, Trigger3D)

protected:
	static void _bind_methods();

    String music;

public:
	virtual bool _activate();
    void set_music(String p_music);
    String get_music();

	TriggerMusic();
	~TriggerMusic();
};

}

#endif //TRIGGER_MUSIC_H
#ifndef TRIGGER_SOUNT_H
#define TRIGGER_SOUNT_H


#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>
#include <godot_cpp/classes/util.hpp>


namespace godot {

class TriggerSound : public Trigger3D {
	GDCLASS(TriggerSound, Trigger3D)

protected:
	static void _bind_methods();

    String sound;

public:
    void set_sound(String p_sound);
    String get_sound();

	virtual bool _activate();

	TriggerSound();
	~TriggerSound();
};

}

#endif //TRIGGER_SOUNT_H
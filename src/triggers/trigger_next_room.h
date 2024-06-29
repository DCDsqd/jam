#ifndef TRIGGER_NEXT_ROOM_H
#define TRIGGER_NEXT_ROOM_H

#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>

namespace godot {

class TriggerNextRoom : public Trigger3D {
	GDCLASS(TriggerNextRoom, Trigger3D)

protected:
	static void _bind_methods();
	String next_scene;

public:
	virtual bool _activate();

	void set_next_scene(String p_next_scene);
	String get_next_scene();

	TriggerNextRoom();
	~TriggerNextRoom();
};

}

#endif //TRIGGER_NEXT_ROOM_H
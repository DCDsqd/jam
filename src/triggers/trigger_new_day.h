#ifndef TRIGGER_NEW_DAY_H
#define TRIGGER_NEW_DAY_H


#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>
#include <godot_cpp/classes/util.hpp>


namespace godot {

class TriggerNewDay : public Trigger3D {
	GDCLASS(TriggerNewDay, Trigger3D)

protected:
	static void _bind_methods();

public:
	virtual bool _activate();

	TriggerNewDay();
	~TriggerNewDay();
};

}

#endif //TRIGGER_NEW_DAY_H
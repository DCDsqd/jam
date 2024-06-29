#ifndef TRIGGER_TELEPORT_ORDER_H
#define TRIGGER_TELEPORT_ORDER_H


#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>


namespace godot {

class TriggerTeleport : public Trigger3D {
	GDCLASS(TriggerTeleport, Trigger3D)

protected:
	static void _bind_methods();

    NodePath marker;
    NodePath obj;

public:
	virtual bool _activate();

    void set_marker(NodePath p_marker);
    NodePath get_marker();

    void set_obj(NodePath p_obj);
    NodePath get_obj();

	TriggerTeleport();
	~TriggerTeleport();
};

}

#endif //TRIGGER_TELEPORT_ORDER_H
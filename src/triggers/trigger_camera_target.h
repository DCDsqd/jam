#ifndef TRIGGER_CAMERA_TARGET_H
#define TRIGGER_CAMERA_TARGET_H


#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/e_camera.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>


namespace godot {

class TriggerCameraTarget : public Trigger3D {
	GDCLASS(TriggerCameraTarget, Trigger3D)

protected:
	static void _bind_methods();

    NodePath marker;

public:
	virtual bool _activate();

    void set_marker(NodePath p_marker);
    NodePath get_marker();

	TriggerCameraTarget();
	~TriggerCameraTarget();
};

}

#endif //TRIGGER_CAMERA_TARGET_H
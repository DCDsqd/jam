#ifndef TRIGGER_CAFE_GET_ORDER_H
#define TRIGGER_CAFE_GET_ORDER_H


#include <vector>

#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/model_entity.hpp>


namespace godot {

class TriggerCafeGetOrder : public Trigger3D {
	GDCLASS(TriggerCafeGetOrder, Trigger3D)

protected:
	static void _bind_methods();
	
    std::vector<ModelEntity *> entities;

public:
	virtual bool _activate();

	TriggerCafeGetOrder();
	~TriggerCafeGetOrder();
};

}

#endif //TRIGGER_CAFE_GET_ORDER_H
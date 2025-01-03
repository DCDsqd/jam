#ifndef CAFE_GET_ORDER_INTERACTOR_H
#define CAFE_GET_ORDER_INTERACTOR_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>

namespace godot {

class CaffeController;

class CafeGetOrderInteractor : public Interaction {
	GDCLASS(CafeGetOrderInteractor, Interaction)

protected:
    static void _bind_methods();

    String order_name;
    Vector3 pos;
    bool has_order = true;
    CaffeController *controller = nullptr;

    void spawn_cloud(String name);

public:
    void set_order_name(String p_order_name);
    void set_has_order(bool p_has_order);
    void set_pos(Vector3 p_pos);
    void set_controller(CaffeController *p_controller);
    String get_order_name();
    Vector3 get_pos();

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    CafeGetOrderInteractor();
    ~CafeGetOrderInteractor();
};

}

#endif // CAFE_GET_ORDER_INTERACTOR_H
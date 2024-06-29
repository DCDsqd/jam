#ifndef CAFE_PUT_ORDER_INTERACTOR_H
#define CAFE_PUT_ORDER_INTERACTOR_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>

namespace godot {

class CaffeController;

class CafePutOrderInteractor : public Interaction {
	GDCLASS(CafePutOrderInteractor, Interaction)

protected:
    static void _bind_methods();

    String order_name;
    CaffeController *controller = nullptr;
    Vector3 pos;

public:
    void set_controller(CaffeController *p_controller);
    void set_order_name(String p_order_name);
    void set_pos(Vector3 p_pos);
    String get_order_name();
    Vector3 get_pos();

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    CafePutOrderInteractor();
    ~CafePutOrderInteractor();
};

}

#endif // CAFE_PUT_ORDER_INTERACTOR_H
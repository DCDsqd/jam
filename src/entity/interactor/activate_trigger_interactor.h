#ifndef ACTIVATE_TRIGGER_INTERACTOR_H
#define ACTIVATE_TRIGGER_INTERACTOR_H

#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>

namespace godot {

class ActivateTriggerInteractor : public Interaction {
	GDCLASS(ActivateTriggerInteractor, Interaction)

protected:
    static void _bind_methods();

    String trigger_name;

public:
    void set_trigger(String p_trigger_name);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    ActivateTriggerInteractor();
    ~ActivateTriggerInteractor();
};

}

#endif // ACTIVATE_TRIGGER_INTERACTOR_H
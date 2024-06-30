#ifndef SLEEP_INTERACTOR_H
#define SLEEP_INTERACTOR_H

#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class SleepInteractor : public Interaction {
	GDCLASS(SleepInteractor, Interaction)

protected:
    static void _bind_methods();

    String model_path;

    void spawn_game(Entity *p_entity);

public:
    void set_view_model(String p_model_path);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    SleepInteractor();
    ~SleepInteractor();
};

}

#endif // SLEEP_INTERACTOR_H
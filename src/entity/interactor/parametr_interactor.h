#ifndef PARAMETR_INTERACTOR_H
#define PARAMETR_INTERACTOR_H

#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/trigger3d.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include "variants/hero_stats.hpp"


namespace godot {

class ParametrInteractor : public Interaction {
	GDCLASS(ParametrInteractor, Interaction)

protected:
    static void _bind_methods();

    HashMap<String, float> map_check_param_entity;
    HashMap<String, int> map_check_param_controller;

    HashMap<String, float> map_plus_param_entity;
    HashMap<String, int> map_plus_param_controller;
    
    bool add_day = false;

    bool check_valide(Entity *p_entity);
    bool check_value(Entity *p_entity);
    void set_value(Entity *p_entity);

public:
    void check_param_entity(String key, float value);
    void check_param_controller(String key, int value);

    void plus_param_entity(String key, float value);
    void plus_param_controller(String key, int value);

    void set_add_day(bool p_add_day);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    ParametrInteractor();
    ~ParametrInteractor();
};

}

#endif // PARAMETR_INTERACTOR_H
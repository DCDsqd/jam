#ifndef ENTITY_BUILDER_H
#define ENTITY_BUILDER_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/entity_builder.hpp>

namespace godot {

class SimpleEntityBuilder : public EntityBuilder {
	GDCLASS(SimpleEntityBuilder, EntityBuilder)

protected:
	static void _bind_methods();

public:
	void set_jump_timer(float p_jumpt_timer);
    void set_speed(float p_speed);
    void set_jump_str(float p_jump_str);
    void set_gravity(float p_gravity);
    void set_coyot_timer(float p_coyot_timer);
    void set_jump_save_timer(float p_jump_save_timer);
    void set_velocity(float p_velocity);
    void set_friction(float p_friction);

    void set_stats(float chill);

    void set_move_sound_modifier(float p_step_sound_modifier);

	SimpleEntityBuilder();
	~SimpleEntityBuilder();
};

}

#endif //ENTITY_BUILDER_H
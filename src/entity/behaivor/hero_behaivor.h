#ifndef HERO_BEHAIVOR_H
#define HERO_BEHAIVOR_H

#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/void_behaivor.hpp>
#include "variants/hero_stats.hpp"

namespace godot {

class HeroBehaivor : public VoidBehaivor {
	GDCLASS(HeroBehaivor, VoidBehaivor)

protected:
	static void _bind_methods();

public:
    void _set_entity(ModelEntity *p_entity) override;
	void _int_process() override;

    void calculate_stats();

	HeroBehaivor();
	~HeroBehaivor();
};

}

#endif //HERO_BEHAIVOR_H
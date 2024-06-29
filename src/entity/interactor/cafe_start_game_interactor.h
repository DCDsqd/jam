#ifndef CAFFE_START_GAME_H
#define CAFFE_START_GAME_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>
#include "util/caffe_controller.h"

namespace godot {

class CaffeStartGameInteractor;

class CaffeStartGameInteractor : public Interaction {
	GDCLASS(CaffeStartGameInteractor, Interaction)

protected:
    static void _bind_methods();

public:
	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    CaffeStartGameInteractor();
    ~CaffeStartGameInteractor();
};

}

#endif //CAFFE_START_GAME_H
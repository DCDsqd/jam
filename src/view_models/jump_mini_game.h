#ifndef JUMP_MINI_GAME_H
#define JUMP_MINI_GAME_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <variants/hero_stats.hpp>
#include <variants/entity_params.hpp>

namespace godot {

class JumpMiniGame : public ViewModel {
	GDCLASS(JumpMiniGame, ViewModel)

private:
    int score = 0;
    int health = 3;

    Entity* player = nullptr;

    void calculate_score();

protected:
    static void _bind_methods();
public:
	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

    int get_score();
    int get_health();

    void add_score();
    void minus_hp();

};


}

#endif // 
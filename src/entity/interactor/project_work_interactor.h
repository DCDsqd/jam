#ifndef PROJECT_WORK_INTERACTOR_H
#define PROJECT_WORK_INTERACTOR_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/view_model.hpp>

#include <set>

namespace godot {

class ProjectWorkInteractor : public Interaction {
	GDCLASS(ProjectWorkInteractor, Interaction)

protected:
    static void _bind_methods();

    String step_two;
    String step_four;

    bool is_avaible(GameController *controller);

public:
    void set_step_two(String p_step_two);
    void set_step_four(String p_step_four);

    void spawn_game(String model_path, Entity *p_entity);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    ProjectWorkInteractor();
    ~ProjectWorkInteractor();
};

}

#endif // TIME_SET_INTERACTOR_H
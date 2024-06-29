#ifndef TIME_SET_INTERACTOR_H
#define TIME_SET_INTERACTOR_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>

#include <set>

namespace godot {

class TimeSetInteractor : public Interaction {
	GDCLASS(TimeSetInteractor, Interaction)

protected:
    static void _bind_methods();

    Interaction *interactor = nullptr;

    std::set<int> alloted_time;
    std::set<String> lock_events;
    bool add_time;

public:
    void set_interactor(Interaction *p_interactor);

    void add_alloted_time(int p_alloted_time);
    void add_lock_event(String p_lock_event);
    void set_is_add_time(bool p_add_time);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    TimeSetInteractor();
    ~TimeSetInteractor();
};

}

#endif // TIME_SET_INTERACTOR_H
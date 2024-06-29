#ifndef VIEW_MODEL_INTERACTOR_H
#define VIEW_MODEL_INTERACTOR_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/interaction.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/hud.hpp>

namespace godot {

class ViewModelInteractor : public Interaction {
	GDCLASS(ViewModelInteractor, Interaction)

protected:
    static void _bind_methods();

    String model_path;

public:
    void set_view_model(String p_model_path);

	bool _interact(Entity *p_entity) override;
	Interaction *_clone() override;

    ViewModelInteractor();
    ~ViewModelInteractor();
};

}

#endif // VIEW_MODEL_INTERACTOR_H
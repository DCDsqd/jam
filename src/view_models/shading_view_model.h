#ifndef SHADING_VIEW_MODEL_H
#define SHADING_VIEW_MODEL_H

#include <godot_cpp/classes/move_component.hpp>
#include <godot_cpp/classes/moving_entity.hpp>
#include <godot_cpp/classes/view_model.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/hud.hpp>
#include <godot_cpp/classes/entity.hpp>
#include <godot_cpp/classes/entity_data.hpp>
#include <godot_cpp/templates/hash_map.hpp>

namespace godot {

class ShadingViewModel : public ViewModel {
	GDCLASS(ShadingViewModel, ViewModel)

protected:
    static void _bind_methods();
    float shading = 0.0f;
    bool start = false;
    Entity* player = nullptr;
    Control *control = nullptr;
    
    HashMap<String, float> plus_score;
    
    void calculate_score();

public:

    void add_plus_score(String key, float value);

	void _open_window(Entity *interaction, Entity *interactor) override;
	void _close_window() override;
	void _int_process() override;

};
}


#endif // SHADING_VIEW_MODEL_H
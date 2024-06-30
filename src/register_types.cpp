#include "register_types.h"

#include "test_dir/gdexample.h"

#include "entity/builder/simple_entity_builder.h"
#include "entity/inputer/human_input.h"

#include "entity/mover/platformer_mover_3d.h"
#include "entity/mover/dino_mover.h"

#include "entity/animator/simple_sprite_animator.h"

#include "entity/interactor/view_model_interactor.h"
#include "entity/interactor/activate_trigger_interactor.h"
#include "entity/interactor/cafe_start_game_interactor.h"
#include "entity/interactor/cafe_get_order_interactor.h"
#include "entity/interactor/cafe_get_order_interactor.h"
#include "entity/interactor/time_set_interactor.h"
#include "entity/interactor/project_work_interactor.h"
#include "entity/interactor/sleep_interactor.h"
#include "entity/interactor/parametr_interactor.h"

#include "entity/behaivor/hero_behaivor.h"

#include "menu/stat_menu.h"
#include "menu/simple_game_menu.h"

#include "view_models/simple_view_model.h"
#include "view_models/jump_mini_game.h"
#include "view_models/multi_selector_model.h"
#include "view_models/shading_view_model.h"
#include "view_models/caffe_result.h"
#include "view_models/end_game_model.h"

#include "triggers/trigger_next_room.h"
#include "triggers/trigger_teleport.h"
#include "triggers/trigger_camera_target.h"
#include "triggers/trigger_music.h"

#include "musical_controller/simple_musical_controller.h"

#include "hud/simple_status_bar.h"

#include "util/param_button.h"
#include "util/caffe_controller.h"
#include "util/bubble_spr.h"


#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<SimpleEntityBuilder>();
	ClassDB::register_class<SimpleSpriteAnimator>();
	ClassDB::register_class<HumanInput>();
	ClassDB::register_class<PlatformerMover3D>();
	ClassDB::register_class<SimpleViewModel>();
	ClassDB::register_class<DinoMover>();

	ClassDB::register_class<ViewModelInteractor>();
	ClassDB::register_class<CafeGetOrderInteractor>();
	ClassDB::register_class<CafePutOrderInteractor>();
	ClassDB::register_class<CaffeStartGameInteractor>();
	ClassDB::register_class<ActivateTriggerInteractor>();
	ClassDB::register_class<TimeSetInteractor>();
	ClassDB::register_class<ProjectWorkInteractor>();
	ClassDB::register_class<SleepInteractor>();
	ClassDB::register_class<ParametrInteractor>();

	ClassDB::register_class<HeroBehaivor>();

	ClassDB::register_class<SimpleGameMenu>();
	ClassDB::register_class<StatMenu>();

	ClassDB::register_class<SimpleStatusBar>();

	ClassDB::register_class<TriggerNextRoom>();
	ClassDB::register_class<TriggerTeleport>();
	ClassDB::register_class<TriggerCameraTarget>();
	ClassDB::register_class<TriggerMusic>();

	ClassDB::register_class<MultiSelectorModel>();
	ClassDB::register_class<JumpMiniGame>();
	ClassDB::register_class<ShadingViewModel>();
	ClassDB::register_class<CaffeResult>();
	ClassDB::register_class<EndGameModel>();

	ClassDB::register_class<SimpleMusicalController>();


	ClassDB::register_class<CaffeController>();
	ClassDB::register_class<ParamButton>();
	ClassDB::register_class<BubbleSpr>();


	
	ClassDB::register_class<GDExample>();
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
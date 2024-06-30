#include "sleep_interactor.h"
#include "util/static_methods.hpp"

void godot::SleepInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_sound_key"), &SleepInteractor::set_sound_key);


    ClassDB::bind_method(D_METHOD("set_view_model"), &SleepInteractor::set_view_model);
}

void godot::SleepInteractor::spawn_game(Entity *p_entity)
{
    Node *node = Util::spawn_node(model_path);
    if(node == nullptr){
        UtilityFunctions::print("ViewModelInteractor: node is not created");
        return;
    }

    ViewModel *model = Object::cast_to<ViewModel>(node);
    if(!model){
        UtilityFunctions::print("ViewModelInteractor: node is not a viewModel");
        return;
    }

    Hud* hud = EternityData::get_singleton()->get_hud();

    if(hud == nullptr){
        UtilityFunctions::print("ViewModelInteractor: hud is null");
        return;
    }

    hud->add_child(model);
    model->open_window(get_entity(), p_entity);
}

void godot::SleepInteractor::set_view_model(String p_model_path)
{
    this->model_path = p_model_path;
}

void godot::SleepInteractor::set_sound_key(String p_sound_key)
{
    this->sound_key = p_sound_key;
}

bool godot::SleepInteractor::_interact(Entity *p_entity)
{
    if(p_entity == nullptr){
        UtilityFunctions::print("SleepInteractor: p_entity is null");
        return false;
    }

    EntityData *data = p_entity->get_data();

    if(data == nullptr){
        UtilityFunctions::print("SleepInteractor: entity data is null");
        return false;
    }
    if(!data->has_float(HeroStats::sleep())){
        UtilityFunctions::print("SleepInteractor: entity data doesn't have: ", HeroStats::sleep());
        return false;
    }

    GameController *controller = EternityData::get_singleton()->get_controller();

    if(controller == nullptr){
        UtilityFunctions::print("SleepInteractor: controller is null");
        return false;
    }

    if(!controller->has_int("game_time")){
        UtilityFunctions::print("SleepInteractor: controller doesn't have game_time");
        return false;
    }

    float sleep = data->get_float(HeroStats::sleep());
    data->put_float(HeroStats::sleep(), sleep + 0.3 * controller->get_int("game_time"));

    spawn_game(p_entity);

    if(sound_key != String())
        StaticMethods::play_sound(sound_key);

    StaticMethods::skip_day();
    
    return true;
}

godot::Interaction *godot::SleepInteractor::_clone()
{
    return memnew(SleepInteractor());
}

godot::SleepInteractor::SleepInteractor()
{
}

godot::SleepInteractor::~SleepInteractor()
{
}

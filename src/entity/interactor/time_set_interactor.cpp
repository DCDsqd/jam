#include "time_set_interactor.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "util/static_methods.hpp"

void godot::TimeSetInteractor::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_interactor"), &TimeSetInteractor::set_interactor);
    ClassDB::bind_method(D_METHOD("add_alloted_time"), &TimeSetInteractor::add_alloted_time);
    ClassDB::bind_method(D_METHOD("add_lock_event"), &TimeSetInteractor::add_lock_event);
    ClassDB::bind_method(D_METHOD("set_is_add_time"), &TimeSetInteractor::set_is_add_time);
}

void godot::TimeSetInteractor::set_interactor(Interaction *p_interactor)
{
    this->interactor = p_interactor;
}

void godot::TimeSetInteractor::add_alloted_time(int p_alloted_time)
{
    this->alloted_time.insert(p_alloted_time);
}

void godot::TimeSetInteractor::add_lock_event(String p_lock_event)
{
    this->lock_events.insert(p_lock_event);
}

void godot::TimeSetInteractor::set_is_add_time(bool p_add_time)
{
    this->add_time = p_add_time;
}

bool godot::TimeSetInteractor::_interact(Entity *p_entity)
{
    if(interactor == nullptr){
        UtilityFunctions::print("TimeSetInteractor: next interactor is null");
        return false;
    }

    if(EternityData::get_singleton()->get_controller() == nullptr){
        UtilityFunctions::print("TimeSetInteractor: controller is null");
        return false;
    }

    GameController *controller = EternityData::get_singleton()->get_controller();
    if(!controller->has_int("game_time") || !controller->has_int("game_day")){
        UtilityFunctions::print("TimeSetInteractor: controller don't have game_time or game_day");
        return false;
    }

    int time = controller->get_int("game_time");
    if(alloted_time.find(time) == alloted_time.end()){
        UtilityFunctions::print("TimeSetInteractor: now not alloted time: ", time);
        StaticMethods::spawn_message(Util::get_value_from_config("word", "bad_time"), 2);
        return false;
    }

    for(String i : lock_events){
        UtilityFunctions::print("TimeSetInteractor: lock event: ", i);
        if(controller->has_int(i) && controller->get_int(i) == 1){
            UtilityFunctions::print("TimeSetInteractor: lock event now");
            StaticMethods::spawn_message(Util::get_value_from_config("word", "bad_event"), 2);
            return false;
        }
    }

    if(add_time){
        StaticMethods::add_time();
        UtilityFunctions::print(controller->get_int("game_time"));
    }

    interactor->set_entity(get_entity());
    interactor->interact(p_entity);

    return false;
}

godot::Interaction *godot::TimeSetInteractor::_clone()
{
    TimeSetInteractor *copy = memnew(TimeSetInteractor);
    copy->set_interactor(interactor);
    return copy;
}

godot::TimeSetInteractor::TimeSetInteractor()
{
}

godot::TimeSetInteractor::~TimeSetInteractor()
{
}

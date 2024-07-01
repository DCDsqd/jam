#include "new_day_model.h"
#include "godot_cpp/variant/utility_functions.hpp"

void godot::NewDayModel::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_new_day_path"), &NewDayModel::set_new_day_path);
    ClassDB::bind_method(D_METHOD("get_new_day_path"), &NewDayModel::get_new_day_path);

    ClassDB::bind_method(D_METHOD("set_old_day_path"), &NewDayModel::set_old_day_path);
    ClassDB::bind_method(D_METHOD("get_old_day_path"), &NewDayModel::get_old_day_path);

    ClassDB::add_property("NewDayModel", PropertyInfo(Variant::NODE_PATH, "new_day_path"), "set_new_day_path", "get_new_day_path");

    ClassDB::add_property("NewDayModel", PropertyInfo(Variant::NODE_PATH, "old_day_path"), "set_old_day_path", "get_old_day_path");
}

void godot::NewDayModel::init_links()
{
    if(has_node(new_day_path) && get_node<Label>(new_day_path)){
        new_day = get_node<Label>(new_day_path); 
    }
    else{
        UtilityFunctions::print("NewDayModel: new_day bad link");
    }

    if(has_node(old_day_path) && get_node<Label>(old_day_path)){
        old_day = get_node<Label>(old_day_path);
    }
    else{
        UtilityFunctions::print("NewDayModel: old_day bad link");
    }
}

void godot::NewDayModel::set_days()
{
    if(new_day == nullptr || old_day == nullptr){
        UtilityFunctions::print("NewDayModel: new_day or old_day is null");
        return;
    }
    

    GameController *controller = EternityData::get_singleton()->get_controller();

    if(controller == nullptr){
        UtilityFunctions::print("NewDayModel: controller is null");
        return;
    }

    if(!controller->has_int("game_day")){
        UtilityFunctions::print("NewDayModel: controller dont have game_day");
        return;
    }

    String tmp1 = "day_" + UtilityFunctions::var_to_str(controller->get_int("game_day")+1);
    String tmp2 = "day_" + UtilityFunctions::var_to_str(controller->get_int("game_day"));

    String day1 = Util::get_value_from_config("word", tmp1);
    String day2 = Util::get_value_from_config("word", tmp2);

    if(day1 == String() || day2 == String()){
        UtilityFunctions::print("NewDayModel: day1 or day2 is null");
        return;
    }

    new_day->set_text(day1);
    old_day->set_text(day2);
}

void godot::NewDayModel::set_new_day_path(NodePath p_new_day_path)
{
    this->new_day_path = p_new_day_path;
}

godot::NodePath godot::NewDayModel::get_new_day_path()
{
    return this->new_day_path;
}

void godot::NewDayModel::set_old_day_path(NodePath p_old_day_path)
{
    this->old_day_path = p_old_day_path;
}

godot::NodePath godot::NewDayModel::get_old_day_path()
{
    return this->old_day_path;
}

void godot::NewDayModel::_open_window(Entity *interaction, Entity *interactor)
{
    init_links();
    set_days();
    if(new_day == nullptr || old_day == nullptr){
        UtilityFunctions::print("NewDayModel: new_day or old_day is null");
        return;
    }

    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("NewDayModel: hud is null");
        return;
    }

    set_physics_process_internal(true);
    hud->lock_game();
    step = 0;
    timer = 100.0f;
}

void godot::NewDayModel::_close_window()
{
    Hud *hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("NewDayModel: hud is null");
        return;
    }

    hud->unlock_game();
}

void godot::NewDayModel::_int_process()
{
    if(new_day == nullptr || old_day == nullptr){
        UtilityFunctions::print("NewDayModel: new_day or old_day is null");
        close_window();
    }

    //UtilityFunctions::print("NewDayModel: step: ", step);
    if(step == 0){
        if(timer-- <= 0.0f){
            step = 1;
        }
    }
    else if(step == 1){
        if(new_day->get_rotation() >= -0.15){
            UtilityFunctions::print(new_day->get_rotation());
            new_day->set_rotation(new_day->get_rotation()-0.1);
            old_day->set_rotation(old_day->get_rotation()-0.1);
        }else{
            timer = 120.0f;
            step = 2;
        }
    }
    else{
        if(timer-- <= 0.0f){
            close_window();
        }
    }

}

#ifndef STATIC_METHOD_H
#define STATIC_METHOD_H

#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include "godot_cpp/variant/utility_functions.hpp"

namespace godot{

class StaticMethods{

public:
    static void add_time(){
        GameController *controller = EternityData::get_singleton()->get_controller();
        if(controller == nullptr){
            UtilityFunctions::print("StaticMethods: controller is null");
            return;
        }
        if(!controller->has_int("game_time") || !controller->has_int("game_day")){
            UtilityFunctions::print("StaticMethods: controller not have game_time or game_day");
            return;
        }

        int time = controller->get_int("game_time");
        int day = controller->get_int("game_day");

        controller->put_int("lock_door", 0);
        
        if(time == 2){
            controller->put_int("game_time", 0);
            controller->put_int("game_day", day+1);
            return;
        }
        controller->put_int("game_time", time+1);
        
    }
    
};

}

#endif // ENTITY_PARAMS_H
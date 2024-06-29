#ifndef ENTITY_PARAMS_H
#define ENTITY_PARAMS_H

#include <godot_cpp/variant/string.hpp>

namespace godot{

class EntityParams{

public:
    static String SPEED(){
        return "move_speed";
    }

    static String JUMP_STR(){
        return "move_jump_str";
    }

    static String GRAVITY(){
        return "move_gravity";
    }

    static String JUMP_TIMER(){
        return "move_jump_timer";
    }
    
    static String COYOT_TIMER(){
        return "move_coyot_timer";
    }

    static String JUMP_SAVE_TIMER(){
        return "move_jump_save_timer";
    }

    static String FRICTION(){
        return "move_friction";
    }

    static String VELOCITY(){
        return "move_velocity";
    }

    static String run_anim(){
        return "run";
    }

    static String idle_anim(){
        return "idle";
    }

    static String step_sound_modifier(){
        return "step_sound_modifier";
    }

};

}

#endif // ENTITY_PARAMS_H
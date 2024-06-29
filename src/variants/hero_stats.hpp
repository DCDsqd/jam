#ifndef HERO_STATS_H
#define HERO_STATS_H

#include <godot_cpp/variant/string.hpp>

namespace godot{

class HeroStats{

public:

    static String cafe_order(){
        return "cafe_order";
    }

    static String chill(){
        return "stat_chill";
    }

    static String friends(){
        return "stat_friend";
    }

    static String happy(){
        return "stat_happy";
    }

    static String sleep(){
        return "stat_sleep";
    }

    static String stress(){
        return "stat_stress";
    }

    static String hunger(){
        return "stat_hunger";
    }

    static String money(){
        return "res_money";
    }

    static String productive(){
        return "res_productive";
    }

    static String effective(){
        return "res_effective";
    }

    static String dream(){
        return "res_dream";
    }

    
};

}

#endif // ENTITY_PARAMS_H
#ifndef TASK_PULL_H
#define TASK_PULL_H

#include <godot_cpp/variant/string.hpp>

namespace godot{

class TaskPull{

public:
    static String Project(){
        return "project_progress";
    }

    static String Work(){
        return "task_work";
    }

    static String AppsCheck(){
        return "apps_check";
    }

    static String HairCut(){
        return "hair_cut";
    }
};

}

#endif // ENTITY_PARAMS_H
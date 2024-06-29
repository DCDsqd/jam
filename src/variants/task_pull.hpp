#ifndef TASK_PULL_H
#define TASK_PULL_H

#include <godot_cpp/variant/string.hpp>

namespace godot{

class TaskPull{

public:
    static String Sleep(){
        return "task_sleep";
    }

    static String Work(){
        return "task_work";
    }

    static String Chill(){
        return "task_chill";
    }

    static String Shop(){
        return "task_shop";
    }
    
    static String FriendMeeting(){
        return "task_friend_meeting";
    }

    static String Trim(){
        return "task_trim";
    }

    static String Teeth(){
        return "task_teeth";
    }

    static String Project(){
        return "task_project";
    }

};

}

#endif // ENTITY_PARAMS_H
#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include <godot_cpp/classes/status_bar.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/classes/eternity_data.hpp>
#include <godot_cpp/classes/game_controller.hpp>
#include <godot_cpp/classes/util.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/animated_texture.hpp>



namespace godot {

class SimpleStatusBar : public StatusBar {
    GDCLASS(SimpleStatusBar, StatusBar);

protected:
    static void _bind_methods();

    TextureRect *time = nullptr;
    Label *day = nullptr;

    NodePath time_path;
    NodePath day_path;

    String get_day(int cur_day);
    void set_time(int cur_time);

public:
    void set_time_path(NodePath p_time_path);
    NodePath get_time_path();

    void set_day_path(NodePath p_day_path);
    NodePath get_day_path();

    void _update_info() override;
	void _init_links() override;

    SimpleStatusBar();
    ~SimpleStatusBar();
};
}

#endif // STATUS_BAR_H
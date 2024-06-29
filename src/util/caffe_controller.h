#ifndef CAFFE_CONTROLLER_H
#define CAFFE_CONTROLLER_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/model_entity.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/trigger3d.hpp>
#include "util/bubble_spr.h"

#include "entity/interactor/cafe_get_order_interactor.h"
#include "entity/interactor/cafe_put_order_interactor.h"

#include <vector>

namespace godot {

class CaffeController : public Node {
	GDCLASS(CaffeController, Node)

private:
    TypedArray<NodePath> clients = Array();
    TypedArray<NodePath> order_tables = Array();
    TypedArray<String> orders = Array();

    Entity *player = nullptr;
    int score = 0;
    int progress = 0;
    float timer = 0.0f;
    bool GAME_STARTED = false;
    int game_step = 0;

    std::vector<CafePutOrderInteractor *> client_nodes;
    std::vector<CafeGetOrderInteractor *> order_table_nodes;

    bool init_order(ModelEntity *mentity);
    bool init_client(ModelEntity *mentity);

    NodePath camera_trigger_1;
    NodePath camera_trigger_2;

    NodePath camera_hero_trigger;

    NodePath end_trigger;

    void show_orders();
    void show_clients();
    void show_player();

protected:
	static void _bind_methods();

public:
    void set_clinets(TypedArray<NodePath> p_clients);
    TypedArray<NodePath> get_clients();

    void set_order_tables(TypedArray<NodePath> p_order_tables);
    TypedArray<NodePath> get_order_tables();

    void set_orders(TypedArray<String> p_orders);
    TypedArray<String> get_orders();

    void set_camera_tirgger_1(NodePath p_camera_trigger_1);
    NodePath get_camera_trigger_1();

    void set_camera_trigger_2(NodePath p_camera_trigger_2);
    NodePath get_camera_trigger_2();

    void set_end_trigger(NodePath p_end_trigger);
    NodePath get_end_trigger();

    void set_camera_hero_trigger(NodePath p_camera_hero_trigger);
    NodePath get_camera_hero_trigger();

    void plus_score(int p_score);
    void add_progress();

    void end_game();
    void start_game(Entity *p_player);

    void _physics_process(float delta);
    void on_process(float delta);

	CaffeController();
	~CaffeController();
};

}

#endif //CAFFE_CONTROLLER_H
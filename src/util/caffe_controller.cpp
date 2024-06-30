#include "caffe_controller.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "variants/hero_stats.hpp"
#include "util/static_methods.hpp"


bool godot::CaffeController::init_order(ModelEntity *mentity)
{
    if(mentity == nullptr){
        UtilityFunctions::print("CaffeController: mentity is null");
        return false;
    }

    Entity * entity = mentity->get_entity();

    if(entity == nullptr){
        UtilityFunctions::print("CaffeController: entity is null");
        return false;
    }

    CafeGetOrderInteractor *interaction = memnew(CafeGetOrderInteractor);
    interaction->set_pos(mentity->get_position());
    interaction->set_has_order(true);
    entity->set_interaction(interaction);

    order_table_nodes.push_back(interaction);
    return true;
}

bool godot::CaffeController::init_client(ModelEntity *mentity)
{
    if(mentity == nullptr){
        UtilityFunctions::print("CaffeController: mentity is null");
        return false;
    }

    Entity * entity = mentity->get_entity();

    if(entity == nullptr){
        UtilityFunctions::print("CaffeController: entity is null");
        return false;
    }

    CafePutOrderInteractor *interaction = memnew(CafePutOrderInteractor);
    interaction->set_pos(mentity->get_position());
    interaction->set_controller(this);
    entity->set_interaction(interaction);

    client_nodes.push_back(interaction);
    return true;
}

void godot::CaffeController::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_clinets"), &CaffeController::set_clinets);
    ClassDB::bind_method(D_METHOD("get_clients"), &CaffeController::get_clients);
    
    ClassDB::bind_method(D_METHOD("set_order_tables"), &CaffeController::set_order_tables);
    ClassDB::bind_method(D_METHOD("get_order_tables"), &CaffeController::get_order_tables);
    
    ClassDB::bind_method(D_METHOD("set_orders"), &CaffeController::set_orders);
    ClassDB::bind_method(D_METHOD("get_orders"), &CaffeController::get_orders);

    
    ClassDB::bind_method(D_METHOD("set_camera_tirgger_1"), &CaffeController::set_camera_tirgger_1);
    ClassDB::bind_method(D_METHOD("get_camera_trigger_1"), &CaffeController::get_camera_trigger_1);
    
    ClassDB::bind_method(D_METHOD("set_camera_trigger_2"), &CaffeController::set_camera_trigger_2);
    ClassDB::bind_method(D_METHOD("get_camera_trigger_2"), &CaffeController::get_camera_trigger_2);
    
    ClassDB::bind_method(D_METHOD("set_end_trigger"), &CaffeController::set_end_trigger);
    ClassDB::bind_method(D_METHOD("get_end_trigger"), &CaffeController::get_end_trigger);
    
    ClassDB::bind_method(D_METHOD("set_camera_hero_trigger"), &CaffeController::set_camera_hero_trigger);
    ClassDB::bind_method(D_METHOD("get_camera_hero_trigger"), &CaffeController::get_camera_hero_trigger);

    ClassDB::add_property("CaffeController", PropertyInfo(Variant::ARRAY, "clients"), "set_clinets", "get_clients");
    ClassDB::add_property("CaffeController", PropertyInfo(Variant::ARRAY, "order_tables"), "set_order_tables", "get_order_tables");
    ClassDB::add_property("CaffeController", PropertyInfo(Variant::ARRAY, "orders"), "set_orders", "get_orders");

    ClassDB::add_property("CaffeController", PropertyInfo(Variant::NODE_PATH, "camera_trigger_1"), "set_camera_tirgger_1", "get_camera_trigger_1");
    ClassDB::add_property("CaffeController", PropertyInfo(Variant::NODE_PATH, "camera_trigger_2"), "set_camera_trigger_2", "get_camera_trigger_2");
    ClassDB::add_property("CaffeController", PropertyInfo(Variant::NODE_PATH, "end_trigger"), "set_end_trigger", "get_end_trigger");
    ClassDB::add_property("CaffeController", PropertyInfo(Variant::NODE_PATH, "camera_hero_trigger"), "set_camera_hero_trigger", "get_camera_hero_trigger");
}

void godot::CaffeController::set_clinets(TypedArray<NodePath> p_clients)
{
    this->clients = p_clients;
}

godot::TypedArray<godot::NodePath> godot::CaffeController::get_clients()
{
    return this->clients;
}

void godot::CaffeController::set_order_tables(TypedArray<NodePath> p_order_tables)
{
    this->order_tables = p_order_tables;
}

godot::TypedArray<godot::NodePath> godot::CaffeController::get_order_tables()
{
    return this->order_tables;
}

void godot::CaffeController::set_orders(TypedArray<String> p_orders)
{
    this->orders = p_orders;
}

godot::TypedArray<godot::String> godot::CaffeController::get_orders()
{
    return this->orders;
}

void godot::CaffeController::set_camera_tirgger_1(NodePath p_camera_trigger_1)
{
    this->camera_trigger_1 = p_camera_trigger_1;
}

godot::NodePath godot::CaffeController::get_camera_trigger_1()
{
    return this->camera_trigger_1;
}

void godot::CaffeController::set_camera_trigger_2(NodePath p_camera_trigger_2)
{
    this->camera_trigger_2 = p_camera_trigger_2;
}

godot::NodePath godot::CaffeController::get_camera_trigger_2()
{
    return this->camera_trigger_2;
}

void godot::CaffeController::set_end_trigger(NodePath p_end_trigger)
{
    this->end_trigger = p_end_trigger;
}

godot::NodePath godot::CaffeController::get_end_trigger()
{
    return this->end_trigger;
}

void godot::CaffeController::set_camera_hero_trigger(NodePath p_camera_hero_trigger)
{
    this->camera_hero_trigger = p_camera_hero_trigger;
}

godot::NodePath godot::CaffeController::get_camera_hero_trigger()
{
    return this->camera_hero_trigger;
}

void godot::CaffeController::show_orders()
{
    if(has_node(camera_trigger_1) && get_node<Trigger3D>(camera_trigger_1)){
        get_node<Trigger3D>(camera_trigger_1)->activate();

        String value = Util::get_value_from_config("util", "bubble_spr");
        if(value == String())
            return;
        
        for(auto order_node : order_table_nodes){
            Node *node = Util::spawn_node(value);

            if(!node->cast_to<BubbleSpr>(node)){
                UtilityFunctions::print("CaffeController: not a bubble_spr");
                return;
            }
                
            BubbleSpr *bubble = node->cast_to<BubbleSpr>(node);
            add_child(bubble);
            bubble->set_position(order_node->get_pos() + Vector3(0.0f, 1.5f, 0.0f));
            bubble->set_scale(Vector3(2.0f, 2.0f, 2.0f));
            bubble->set_sprite(order_node->get_order_name());
        }

        return;
    }
    UtilityFunctions::print("CaffeController: camera_trigger_1 so bad");
}

void godot::CaffeController::show_clients()
{
    if(has_node(camera_trigger_2) && get_node<Trigger3D>(camera_trigger_2)){
        get_node<Trigger3D>(camera_trigger_2)->activate();

        String value = Util::get_value_from_config("util", "bubble_spr");
        if(value == String())
            return;

        for(auto client_node : client_nodes){
            Node *node = Util::spawn_node(value);

            if(!node->cast_to<BubbleSpr>(node)){
                UtilityFunctions::print("CaffeController: not a bubble_spr");
                return;
            }
                
            BubbleSpr *bubble = node->cast_to<BubbleSpr>(node);
            add_child(bubble);
            bubble->set_position(client_node->get_pos() + Vector3(0.0f, 1.5f, 0.0f));
            bubble->set_scale(Vector3(2.0f, 2.0f, 2.0f));
            bubble->set_sprite(client_node->get_order_name());
        }

        return;
    }
    UtilityFunctions::print("CaffeController: camera_trigger_2 so bad");
}

void godot::CaffeController::show_player()
{
    if(has_node(camera_hero_trigger) && get_node<Trigger3D>(camera_hero_trigger)){
        get_node<Trigger3D>(camera_hero_trigger)->activate();
        return;
    }
    UtilityFunctions::print("CaffeController: camera_hero_trigger so bad");
}

bool godot::CaffeController::check_player()
{
    if(player == nullptr){
        UtilityFunctions::print("CaffeController: player is null");
        return false;
    }

    if(player->get_data() == nullptr){
        UtilityFunctions::print("CaffeController: player data is null");
        return false;
    }

    EntityData *data = player->get_data();

    if(!data->has_float(HeroStats::effective())){
        UtilityFunctions::print("CaffeController: effective is null");
        return false;
    }

    if(!data->has_float(HeroStats::productive())){
        UtilityFunctions::print("CaffeController: productive is null");
        return false;
    }

    if(!data->has_float(HeroStats::money())){
        UtilityFunctions::print("CaffeController: money is null");
        return false;
    }

    return true;
}

void godot::CaffeController::calculate_score()
{
    
    if(!check_player()){
        return;
    }

    String info = "";

    float start_money = 500.0f;
    float effective = player->get_data()->get_float(HeroStats::effective());
    float time_bonus = effective*30.0f - timer;
    if(time_bonus < 0.5f){
        time_bonus = 0.5f;
    }

    float productive = player->get_data()->get_float(HeroStats::productive());

    float result = start_money * (1 + score/10 + time_bonus/10)*productive;

    info += Util::get_value_from_config("word", "result_caffe_score") + 
        UtilityFunctions::var_to_str(score) + "\n";

    info += Util::get_value_from_config("word", "result_caffe_time") + 
        UtilityFunctions::var_to_str(timer) + "\n";
        
    info += Util::get_value_from_config("word", "result_caffe_effective_bonus")  + 
        UtilityFunctions::var_to_str(effective) + "\n";

    info += Util::get_value_from_config("word", "result_caffe_time_bonus") + "5 * " +
        UtilityFunctions::var_to_str(effective) + " - " + UtilityFunctions::var_to_str(timer) + "\n";

    info += " = " + UtilityFunctions::var_to_str(time_bonus) + "\n";

    info += Util::get_value_from_config("word", "result_caffe_productive_bonus")  + 
        UtilityFunctions::var_to_str(productive);

    float money = player->get_data()->get_float(HeroStats::money());
    player->get_data()->put_float(HeroStats::money(), money + result);

    float tmp = player->get_data()->get_float(HeroStats::happy());
    player->get_data()->put_float(HeroStats::happy(), tmp - 0.25);

    show_result(info, "= " + UtilityFunctions::var_to_str(result));
}

void godot::CaffeController::show_result(String info, String result)
{
    String path = Util::get_value_from_config("util", "result_view");
    if(path == String()){
        UtilityFunctions::print("CaffeController: config not found: result_view");
        return;
    }

    Node *node = Util::spawn_node(path);
    if(node == nullptr){
        UtilityFunctions::print("CaffeController: node is not created");
        return;
    }

    CaffeResult *model = Object::cast_to<CaffeResult>(node);
    if(!model){
        UtilityFunctions::print("CaffeController: node is not a CaffeResult");
        return;
    }

    Hud* hud = EternityData::get_singleton()->get_hud();
    if(hud == nullptr){
        UtilityFunctions::print("ViewModelInteractor: hud is null");
        return;
    }
    hud->add_child(model);
    model->open_window(nullptr, player);

    model->set_main_info(info);
    model->set_result_info(result);

}

void godot::CaffeController::plus_score(int p_score)
{
    UtilityFunctions::print("CaffeController: change score on ", p_score);
    this->score += p_score;
}

void godot::CaffeController::add_progress()
{
    this->progress++;
    UtilityFunctions::print("CaffeController: your progress ", progress);
    if(this->orders.size() <= progress){
        end_game();
    }
}

void godot::CaffeController::end_game()
{
    GAME_STARTED = false;
    calculate_score();

    if(has_node(end_trigger) && get_node<Trigger3D>(end_trigger)){
        StaticMethods::add_time();
        get_node<Trigger3D>(end_trigger)->activate();
        return;
    }
    UtilityFunctions::print("CaffeController: end_trigger so bad");
}

void godot::CaffeController::start_game(Entity *p_player)
{
    client_nodes = std::vector<CafePutOrderInteractor *>();
    order_table_nodes = std::vector<CafeGetOrderInteractor *>();

    progress = 0;
    score = 0;
    game_step = 0;

    if(p_player == nullptr){
        UtilityFunctions::print("CaffeController: player is null");
        return;
    }

    for(int i = 0; i < clients.size(); ++i){
        if(has_node(clients[i]) && get_node<ModelEntity>(clients[i])){
            ModelEntity *client = get_node<ModelEntity>(clients[i]);
            init_client(client);
            continue;
        }
        UtilityFunctions::print("CaffeController: client path is incorrect");
    }

    for(int i = 0; i < order_tables.size(); ++i){
        if(has_node(order_tables[i]) && get_node<ModelEntity>(order_tables[i])){
            ModelEntity *order_table = get_node<ModelEntity>(order_tables[i]);
            init_order(order_table);
            //order_table_nodes.push_back(order_table);
            continue;
        }
        UtilityFunctions::print("CaffeController: client path is incorrect");
    }

    if(order_table_nodes.size() != orders.size() || client_nodes.size() != orders.size()){
        UtilityFunctions::print("CaffeController: bad size of vectors");
        UtilityFunctions::print("CaffeController: order size: ", orders.size());
        UtilityFunctions::print("CaffeController: order_table size: ", order_table_nodes.size());
        UtilityFunctions::print("CaffeController: client_nodes size", client_nodes.size());

        return;
    }

    this->player = p_player;

    RandomNumberGenerator *rnd = new RandomNumberGenerator();

    std::vector<String> pull_orders;
    for(int i = 0; i < orders.size(); ++i){
        pull_orders.push_back(orders[i]);
    }
    std::vector<CafePutOrderInteractor *> pull_clients = client_nodes;
    std::vector<CafeGetOrderInteractor *> pull_order_tables = order_table_nodes;

    for(int i = 0; i < orders.size(); ++i){
        int current_order_id = rnd->randi_range(0, pull_orders.size()-1);
        String current_order = pull_orders[current_order_id];
        pull_orders.erase(pull_orders.begin() + current_order_id);

        int current_client_id = rnd->randi_range(0, pull_clients.size()-1);
        CafePutOrderInteractor *current_client = pull_clients[current_client_id];
        pull_clients.erase(pull_clients.begin() + current_client_id);

        int current_order_table_id = rnd->randi_range(0, pull_order_tables.size()-1);
        CafeGetOrderInteractor *current_order_table = pull_order_tables[current_order_table_id];
        pull_order_tables.erase(pull_order_tables.begin() + current_order_table_id);

        current_client->set_order_name(current_order);
        current_order_table->set_order_name(current_order);

    }

    GAME_STARTED = true;
    show_orders();
    
}

void godot::CaffeController::_physics_process(float delta)
{
    if(!Engine::get_singleton()->is_editor_hint() && GAME_STARTED){
        on_process(delta);
    }
}

void godot::CaffeController::on_process(float delta)
{
    timer+=delta;
    
    if(timer >= 5.0f && game_step == 0){
        show_clients();
        game_step = 1;
    }

    if(timer >= 10.0f && game_step == 1){
        show_player();
        game_step = 2;
    }
}

godot::CaffeController::CaffeController()
{
}

godot::CaffeController::~CaffeController()
{
}

#include "simple_sprite_animator.h"
#include <godot_cpp/variant/vector3.hpp>
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/util.hpp"

void godot::SimpleSpriteAnimator::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("parse_from_json"), &SimpleSpriteAnimator::parse_from_json);
}

void godot::SimpleSpriteAnimator::_set_animation(const String &animation, int32_t speed)
{
    ModelEntity *entity = get_entity();
    
    entity->get_model()->set_animation(animation);
}

int32_t godot::SimpleSpriteAnimator::_has_animation()
{
    return 0;
}

void godot::SimpleSpriteAnimator::_set_rotation(const Vector3 &rot)
{
    if(rot.length_squared() == 0)
        return;

    ModelEntity *entity = get_entity();
    
    if(rot.x > 0){
        entity->get_model()->flip_h(false);
    }
    else{
        entity->get_model()->flip_h(true);
    }
}

godot::Vector3 godot::SimpleSpriteAnimator::_get_rotation()
{
    return Vector3();
}

void godot::SimpleSpriteAnimator::_play_sound(const String &name)
{
    if(!bind_map.has(name)){
        UtilityFunctions::print("SimpleSpriteAnimator: " + name +" sound not found");
        return;
    }

    AudioStreamPlayer3D *player = get_entity()->get_audio_player();
    player->set_stream(bind_map[name]);
    player->play();
}

void godot::SimpleSpriteAnimator::set_audio_map(HashMap<String, Ref<AudioStream>> p_bind_map)
{
    this->bind_map = p_bind_map;
}

void godot::SimpleSpriteAnimator::parse_from_json(String path)
{
    String text = FileAccess::get_file_as_string(path);
    if(text == String()){
        UtilityFunctions::print("SimpleSpriteAnimator: file not found");
        return;
    }
    
    Dictionary dict = JSON::parse_string(text);
    if(!dict.has("animator")){
        UtilityFunctions::print("SimpleSpriteAnimator: animator not found");
        return;
    }
    Dictionary params = dict.get("animator", "");

    if(params.has("bind_map")){
        UtilityFunctions::print("SimpleSpriteAnimator: start parse bind map");
        parse_audio_map(params.get("bind_map", Dictionary()));
    }
    
}

void godot::SimpleSpriteAnimator::parse_audio_map(Dictionary map)
{
    if(map == Dictionary()){
        UtilityFunctions::print("SimpleSpriteAnimator: error on load map");
        return;
    }

    Array keys = map.keys();
    for(int i = 0; i < keys.size(); ++i){
        bind_map[keys[i]] = Util::load_music(map[keys[i]]);
    }
    
}

godot::SimpleSpriteAnimator::SimpleSpriteAnimator()
{
}

godot::SimpleSpriteAnimator::~SimpleSpriteAnimator()
{
}

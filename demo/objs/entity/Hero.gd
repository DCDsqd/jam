extends MovingEntity

var timer = 10.0

func _ready():
	var builder : SimpleEntityBuilder = SimpleEntityBuilder.new()
	#var data : EntityData = EntityDataImpl.new()
	
	#data.put_float("speed", 0.1)
	builder.set_data(EntityDataImpl.new())
	
	builder.set_speed(1.5)
	builder.set_gravity(1)
	
	builder.set_velocity(0.2)
	builder.set_friction(0.1)
	builder.set_move_sound_modifier(10.0)
	
	builder.set_jump_str(0)
	builder.set_jump_timer(0)
	builder.set_coyot_timer(0)
	builder.set_jump_save_timer(0)
	
	builder.set_stats(1.0)
	
	#set_entity(Entity.new())
	set_entity(builder.get_entity())
	
	var animator : SimpleSpriteAnimator = SimpleSpriteAnimator.new()
	var input : HumanInput = HumanInput.new()
	input.set_select_entity(true)
	animator.parse_from_json("res://res/entity/hero/hero_params.json")
	set_animator(animator)
	set_input_component(input)
	set_move_component(PlatformerMover3D.new())
	set_behaivor(HeroBehaivor.new())

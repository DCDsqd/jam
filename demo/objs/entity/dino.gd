extends MovingEntity


func _ready():
	var entity = Entity.new()
	var data = EntityDataImpl.new()
	
	
	entity.set_data(data)
	set_entity(entity)
	
	var mover : DinoMover = DinoMover.new()
	
	mover.set_jump_str(2.8)
	mover.set_jump_timer(0.2)
	
	set_pausable(false)
	
	set_input_component(HumanInput.new())
	set_move_component(mover)
	

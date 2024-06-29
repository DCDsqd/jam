extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()
	
	var interaction : ViewModelInteractor = ViewModelInteractor.new()
	
	
	
	interaction.set_view_model("res://objs/mini_games/jump_game/JumpMiniGame.tscn");
	
	entity.set_data(data)
	entity.set_interaction(interaction)
	
	set_entity(entity)
	

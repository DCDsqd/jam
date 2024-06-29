extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()
	var interaction : ViewModelInteractor = ViewModelInteractor.new()
	
	interaction.set_view_model("res://objs/view_models/pc_selector.tscn");
	
	entity.set_data(data)
	entity.set_interaction(interaction)
	
	set_entity(entity)
	

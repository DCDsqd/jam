extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()
	var interaction : TimeSetInteractor = TimeSetInteractor.new()
	
	interaction.add_alloted_time(1)
	interaction.add_alloted_time(2)
	interaction.set_is_add_time(false)
	
	var bed : ViewModelInteractor = ViewModelInteractor.new()
	
	bed.set_view_model("res://objs/view_models/sleep_selector.tscn");
	
	interaction.set_interactor(bed)
	
	entity.set_data(data)
	entity.set_interaction(interaction)
	
	set_entity(entity)
	

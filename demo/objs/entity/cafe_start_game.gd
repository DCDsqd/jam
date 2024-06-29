extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()
	var interaction : CaffeStartGameInteractor = CaffeStartGameInteractor.new()
	
	entity.set_data(data)
	entity.set_interaction(interaction)
	set_entity(entity)
	

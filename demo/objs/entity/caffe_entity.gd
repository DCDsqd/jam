extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()

	entity.set_data(data)
	set_entity(entity)
	

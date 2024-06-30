extends ModelEntity


func _ready():
	var entity : Entity = Entity.new()
	var data : EntityData = EntityDataImpl.new()
	var shop : ViewModelInteractor = ViewModelInteractor.new()
	
	shop.set_view_model("res://objs/view_models/shop_selector.tscn");
	
	entity.set_data(data)
	entity.set_interaction(shop)
	
	set_entity(entity)
	

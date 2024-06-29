extends Button


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass

func _pressed():
	var model : SimpleViewModel = $"../.."
	if model == null:
		return
		
	model.set_param(10)
	model.close_window()

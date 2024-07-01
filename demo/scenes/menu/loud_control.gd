extends HSlider


# Called when the node enters the scene tree for the first time.
func _ready():
	max_value = 20.0
	min_value = -50.0
	value = 0.0


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _value_changed(new_value):
	AudioServer.set_bus_volume_db(0, new_value)

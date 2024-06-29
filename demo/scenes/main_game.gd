extends SimpleGameController


# Called when the node enters the scene tree for the first time.
func _ready():
	put_int("part_of_day", 0)
	put_int("day", 0)
	put_int("project_step", 0)
	
	swap_scene("res://scenes/home.tscn")


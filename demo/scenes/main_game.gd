extends SimpleGameController


# Called when the node enters the scene tree for the first time.
func _ready():
	put_int("game_time", 0)
	put_int("game_day", 0)
	put_int("project_progress", 0)
	
	swap_scene("res://scenes/home.tscn")


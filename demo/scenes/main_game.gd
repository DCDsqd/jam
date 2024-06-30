extends SimpleGameController


# Called when the node enters the scene tree for the first time.
func _ready():
	put_int("game_time", 0)
	put_int("game_day", 0)
	put_int("project_progress", 0)
	put_int("apps_check", 0)
	put_int("hair_cut", 0)
	
	put_int("item_meat", 0)
	put_int("item_coffe", 0)
	put_int("item_bar", 0)
	
	swap_scene("res://scenes/home.tscn")


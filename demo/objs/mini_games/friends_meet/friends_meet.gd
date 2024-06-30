extends ShadingViewModel


func _ready():
	add_plus_score("stat_happy", 0.4)
	add_plus_score("stat_sleep", -0.2)
	set_message("Вы встретились с друзьями")

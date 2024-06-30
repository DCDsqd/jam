extends MultiSelectorModel


func _ready():
	var time_skip : SleepInteractor = SleepInteractor.new()
	time_skip.set_view_model("res://objs/mini_games/jump_game/SleepGame.tscn")
	
	var cancel_interactor : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	add_interactor("Лечь спать", time_skip)
	add_interactor("Отмена", cancel_interactor)
	
	#add_interactor("Пойти в кафе", )


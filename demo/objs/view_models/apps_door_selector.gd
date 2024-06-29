extends MultiSelectorModel


func _ready():
	var interactor1 : ActivateTriggerInteractor = ActivateTriggerInteractor.new()
	interactor1.set_trigger("go_to_cafe")
	
	var interactor2 : ViewModelInteractor = ViewModelInteractor.new()
	interactor2.set_view_model("res://objs/mini_games/jump_game/JumpMiniGame.tscn");
	
	set_offset(Vector2(20, 120))
	add_interactor("Пойти в кафе", interactor1)
	add_interactor("Позалипать", interactor2)
	
	#add_interactor("Пойти в кафе", )


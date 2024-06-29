extends MultiSelectorModel


func _ready():
	var cafe_interactor : ActivateTriggerInteractor = ActivateTriggerInteractor.new()
	cafe_interactor.set_trigger("go_to_cafe")
	
	var interactor1 : TimeSetInteractor = TimeSetInteractor.new();
	interactor1.add_alloted_time(0)
	interactor1.set_is_add_time(true)
	interactor1.set_interactor(cafe_interactor)
	
	var interactor2 : ViewModelInteractor = ViewModelInteractor.new()
	interactor2.set_view_model("res://objs/mini_games/jump_game/JumpMiniGame.tscn");
	
	set_offset(Vector2(20, 120))
	add_interactor("Пойти в кафе", interactor1)
	add_interactor("Позалипать", interactor2)
	
	#add_interactor("Пойти в кафе", )


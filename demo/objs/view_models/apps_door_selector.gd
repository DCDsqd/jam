extends MultiSelectorModel


func _ready():
	var cafe_interactor : ActivateTriggerInteractor = ActivateTriggerInteractor.new()
	cafe_interactor.set_trigger("go_to_cafe")
	
	var interactor1 : TimeSetInteractor = TimeSetInteractor.new();
	interactor1.add_alloted_time(0)
	interactor1.set_is_add_time(false)
	interactor1.set_interactor(cafe_interactor)
	
	var friends_meet : ViewModelInteractor = ViewModelInteractor.new()
	friends_meet.set_view_model("res://objs/mini_games/cleaning/clean_skip.tscn")
	
	var interactor2 : TimeSetInteractor = TimeSetInteractor.new();
	interactor2.add_alloted_time(0)
	interactor2.add_alloted_time(1)
	interactor2.set_is_add_time(true)
	interactor2.set_interactor(friends_meet)
	
	var cancel : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	add_interactor("Пойти в кафе", interactor1)
	add_interactor("Встретиться с друзьями", interactor2)
	add_interactor("Отмена", cancel)
	
	#add_interactor("Пойти в кафе", )


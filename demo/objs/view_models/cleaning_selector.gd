extends MultiSelectorModel


func _ready():
	var clean_interactor : ViewModelInteractor = ViewModelInteractor.new()
	clean_interactor.set_view_model("res://objs/mini_games/cleaning/clean_skip.tscn")
	var time_skip : TimeSetInteractor = TimeSetInteractor.new()
	time_skip.add_alloted_time(0)
	time_skip.add_alloted_time(1)
	time_skip.add_alloted_time(2)
	time_skip.set_interactor(clean_interactor)
	time_skip.set_is_add_time(true)
	
	var cancel_interactor : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	add_interactor("Начать уборку", time_skip)
	add_interactor("Отмена", cancel_interactor)
	
	#add_interactor("Пойти в кафе", )


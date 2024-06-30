extends MultiSelectorModel


func _ready():
	var project_interactor : ProjectWorkInteractor = ProjectWorkInteractor.new()
	project_interactor.set_step_two("res://objs/mini_games/project_work/project_work.tscn")
	project_interactor.set_step_four("res://objs/mini_games/project_work/project_work.tscn")
	
	var chill_timer : TimeSetInteractor = TimeSetInteractor.new()
	
	chill_timer.add_alloted_time(0)
	chill_timer.add_alloted_time(1)
	chill_timer.add_alloted_time(2)
	chill_timer.set_is_add_time(true)
	
	var chill_interactor : ViewModelInteractor = ViewModelInteractor.new()
	chill_interactor.set_view_model("res://objs/mini_games/jump_game/JumpMiniGame.tscn");
	
	chill_timer.set_interactor(chill_interactor)
	
	set_offset(Vector2(20, 120))
	add_interactor("Делать проект", project_interactor)
	add_interactor("Позалипать", chill_timer)
	
	#add_interactor("Пойти в кафе", )


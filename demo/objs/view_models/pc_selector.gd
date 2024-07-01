extends MultiSelectorModel


func _ready():
	var project_interactor : ProjectWorkInteractor = ProjectWorkInteractor.new()
	project_interactor.set_step_two("res://objs/mini_games/project_work/project_work.tscn")
	project_interactor.set_step_four("res://objs/mini_games/project_work/project_work.tscn")
	project_interactor.set_sound_key("sound_project")
	
	var chill_timer : TimeSetInteractor = TimeSetInteractor.new()
	
	chill_timer.add_alloted_time(0)
	chill_timer.add_alloted_time(1)
	chill_timer.add_alloted_time(2)
	chill_timer.set_is_add_time(false)
	
	var chill_interactor : ViewModelInteractor = ViewModelInteractor.new()
	chill_interactor.set_sound_key("sound_chill")
	chill_interactor.set_view_model("res://objs/mini_games/jump_game/JumpMiniGame.tscn");
	
	chill_timer.set_interactor(chill_interactor)
	
	var cancel : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	add_interactor("Делать проект", project_interactor)
	add_interactor("Отдохнуть", chill_timer)
	add_interactor("Отменить", cancel)
	pay_check()
	#add_interactor("Пойти в кафе", )

func pay_check():
	if(!EternityData.get_controller()):
		return
	
	if(!EternityData.get_controller().has_int("game_day")):
		return
	
	if(!EternityData.get_controller().has_int("apps_check")):
		return
	
	if(EternityData.get_controller().get_int("game_day") != 4):
		return
		
	if(EternityData.get_controller().get_int("apps_check") != 0):
		return
	
	var interactor : ParametrInteractor = ParametrInteractor.new()
	interactor.check_param_entity("res_money", 2000.0)
	interactor.plus_param_controller("apps_check", 1)
	interactor.plus_param_entity("res_money", -2000.0)
	interactor.set_sound_key("sound_pay")
	add_interactor("Заплатить за квартиру (2000)", interactor)
	


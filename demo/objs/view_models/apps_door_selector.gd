extends MultiSelectorModel


func _ready():
	var cafe_interactor : ActivateTriggerInteractor = ActivateTriggerInteractor.new()
	cafe_interactor.set_trigger("go_to_cafe")
	cafe_interactor.set_sound_key("sound_work");
	
	var interactor1 : TimeSetInteractor = TimeSetInteractor.new();
	interactor1.add_alloted_time(0)
	interactor1.set_is_add_time(false)
	interactor1.set_interactor(cafe_interactor)
	
	var friends_meet : ViewModelInteractor = ViewModelInteractor.new()
	friends_meet.set_view_model("res://objs/mini_games/friends_meet/friends_meet.tscn")
	friends_meet.set_sound_key("sound_friends")
	
	var interactor2 : TimeSetInteractor = TimeSetInteractor.new();
	interactor2.add_alloted_time(0)
	interactor2.add_alloted_time(1)
	interactor2.set_is_add_time(true)
	interactor2.set_interactor(friends_meet)
	
	var shop_interactor : ActivateTriggerInteractor = ActivateTriggerInteractor.new()
	shop_interactor.set_trigger("go_to_shop")
	shop_interactor.set_sound_key("sound_shop")
	
	var interactor3 : TimeSetInteractor = TimeSetInteractor.new();
	interactor3.add_alloted_time(1)
	interactor3.add_alloted_time(2)
	interactor3.set_is_add_time(false)
	interactor3.set_interactor(shop_interactor)
	
	var cancel : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	add_interactor("Работать в кафе", interactor1)
	add_interactor("Встретиться с друзьями", interactor2)
	add_interactor("Сходить в магазин", interactor3)
	add_interactor("Отмена", cancel)
	
	eventer()
	#add_interactor("Пойти в кафе", )

func eventer():
	if(!EternityData.get_controller()):
		return
	
	if(!EternityData.get_controller().has_int("game_day") or !EternityData.get_controller().has_int("game_time")):
		return
		
	var day : int = EternityData.get_controller().get_int("game_day")
	var time : int = EternityData.get_controller().get_int("game_time")
	
	if(day == 3 and time == 1):
		add_hair()
	

func add_hair():
	var hair_cutter : ParametrInteractor = ParametrInteractor.new()
	hair_cutter.check_param_entity("res_money", 500.0)
	hair_cutter.plus_param_controller("hair_cut", 1)
	hair_cutter.plus_param_entity("res_money", -500.0)
	hair_cutter.set_add_day(true)
	add_interactor("Сходить в парихмахерскую", hair_cutter)

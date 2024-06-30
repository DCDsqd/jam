extends MultiSelectorModel


func _ready():
	
	var use_coffe : ParametrInteractor = ParametrInteractor.new()
	use_coffe.check_param_controller("item_coffe", 1)
	use_coffe.plus_param_entity("stat_sleep", 0.1)
	use_coffe.plus_param_entity("stat_hunger", -0.1)
	use_coffe.plus_param_controller("item_coffe", -1)
	use_coffe.set_add_day(false)
	
	var use_bar : ParametrInteractor = ParametrInteractor.new()
	use_bar.check_param_controller("item_bar", 1)
	use_bar.plus_param_entity("stat_hunger", 0.1)
	use_bar.plus_param_controller("item_bar", -1)
	use_bar.set_add_day(false)
	
	var use_meat : ParametrInteractor = ParametrInteractor.new()
	use_meat.check_param_controller("item_meat", 1)
	use_meat.plus_param_entity("stat_hunger", 0.25)
	use_meat.plus_param_controller("item_meat", -1)
	use_meat.set_add_day(false)
	
	
	var cancel_interactor : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	
	if(EternityData.get_controller()):
		add_interactor("Выпить коффе (" + var_to_str(EternityData.get_controller().get_int("item_coffe")) + ")", use_coffe)
		add_interactor("Сьесть батончик (" + var_to_str(EternityData.get_controller().get_int("item_bar")) + ")", use_bar)
		add_interactor("Сьесть мясо (" + var_to_str(EternityData.get_controller().get_int("item_meat")) + ")", use_meat)
	
	add_interactor("Отмена", cancel_interactor)
	
	#add_interactor("Пойти в кафе", )


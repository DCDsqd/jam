extends MultiSelectorModel


func _ready():
	
	var buy_coffe : ParametrInteractor = ParametrInteractor.new()
	buy_coffe.check_param_entity("res_money", 150.0)
	buy_coffe.plus_param_controller("item_coffe", 1)
	buy_coffe.plus_param_entity("res_money", -150.0)
	buy_coffe.set_succesfull("Вы купили кофе")
	buy_coffe.set_add_day(false)
	
	var buy_bar : ParametrInteractor = ParametrInteractor.new()
	buy_bar.check_param_entity("res_money", 120.0)
	buy_bar.plus_param_controller("item_bar", 1)
	buy_bar.plus_param_entity("res_money", -120.0)
	buy_bar.set_succesfull("Вы купили батончик")
	buy_bar.set_add_day(false)
	
	var buy_meat : ParametrInteractor = ParametrInteractor.new()
	buy_meat.check_param_entity("res_money", 200.0)
	buy_meat.plus_param_controller("item_meat", 1)
	buy_meat.plus_param_entity("res_money", -200.0)
	buy_meat.set_succesfull("Вы купили мясо")
	buy_meat.set_add_day(false)
	
	
	var cancel_interactor : Interaction = Interaction.new()
	
	set_offset(Vector2(20, 120))
	
	add_interactor("Купить коффе (150р)", buy_coffe)
	add_interactor("Купить батончик (120р)", buy_bar)
	add_interactor("Купить мясо (200р)", buy_meat)
	add_interactor("Отмена", cancel_interactor)
	
	#add_interactor("Пойти в кафе", )


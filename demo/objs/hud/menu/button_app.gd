extends Button

func _pressed():
	$"../RichTextLabel".set_text(Util.get_value_from_config("rich_texts", "apps_pay"))

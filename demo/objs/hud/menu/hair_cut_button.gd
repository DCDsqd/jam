extends Button


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _pressed():
	$"../RichTextLabel".set_text(Util.get_value_from_config("rich_texts", "hair_cut"))

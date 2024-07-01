extends Area3D


func _ready():
	connect("area_entered", _area_change)
	connect("area_exited", _area_change)

func _area_change(area : Area3D):
	$"../Sprite3D".set_visible(get_overlapping_areas().size() > 0)

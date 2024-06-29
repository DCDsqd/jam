extends Area3D


# Called when the node enters the scene tree for the first time.
func _ready():
	connect("body_entered", _body_entred)


func _body_entred(body : Node3D):
	print("body entred")
	
	var trigger : Trigger3D = get_parent()
	if(trigger):
		trigger.activate()
	

extends Node3D

var step : int = 0
var start : Vector3
var end : Vector3

# Called when the node enters the scene tree for the first time.
func _ready():
	start = position
	end = position - Vector3(0, 0, -1)
	step = 0


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	if(step == 0):
		if(position.distance_to(end) >= 0.3):
			smooth_move(end)
		else:
			step = 1
			
	else:
		if(position.distance_to(start) >= 0.3):
			smooth_move(start)
		else:
			step = 0
		
		
func smooth_move(pos):
	var dir = position.direction_to(pos)
	position += dir * (position.distance_to(pos)) * 0.005

extends Area3D

var speed = 0.05

# Called when the node enters the scene tree for the first time.
func _ready():
	connect("area_entered", _area_entred)
	connect("body_entered", _body_entered)
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	position.x -= speed


func _body_entered(_node : Node3D):
	var marker : Marker3D = $"../Marker3D"
	var game : JumpMiniGame = $"../../../../.."
	position = marker.position
	speed = 0.05
	game.minus_hp()
	

func _area_entred(_area : Area3D):
	var marker : Marker3D = $"../Marker3D"
	var game : JumpMiniGame = $"../../../../.."
	speed += 0.01
	position = marker.position
	game.add_score()

extends Resource
class_name CNodeConnectionResource

enum InputType { WIRE, INT, FLOAT, ENUM }

@export var name: String

@export var id: StringName
@export var min_value: float = 0.0
@export var max_value: float = 1.0
@export var default_value: float = 0.0
@export var options: PackedStringArray

@export var input_type = InputType.WIRE
@export var enable_left_port: bool = true
@export var type_left_port: int = 0
@export var wire_color_left_port: Color = Color.BLUE

@export var enable_right_port: bool = false
@export var type_right_port: int = 0
@export var wire_color_right_port: Color = Color.BLUE

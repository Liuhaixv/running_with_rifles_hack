# running_with_rifles_hack
 hack for RWR

# offsets

## crosshair_status
no target:0
yellow crosshair point(clear to shoot enemy):1
red crosshair point(unable to hit aim-point):2
not in game or dead:3 or 11
rwr_game.exe+004FB4D4 -> 8 24 2c 8 8 1494 8
rwr_game.exe+004FB4D4 -> 2C 8 24 30 34 1494 8

## shoot_control
shooting:2
stop_shooting:1

0
0



## 站蹲趴

 x->
y
|
v
## 瞄准视野位置 x y
每一个大格子是100.0
stuct {
	float x;
	float ?;
	flaot y;
}

struct Point{
	float x;
	float z;
	float y;
}


float * 4 * 4 = 64byte
struct PositionInfo {
	Point currentTick;
	Point previousTick;
	
}

struct PlayerPositions{
	Position player;
	byte[12] padding;
	...
	Position player;
	byte[12] padding;
	...
}

Point local_player{
	float x = rwr_game.exe + 004FB4D4 -> 2C 20 24 20 0 34 D18 4 B4 A
	float z = 
	float y = 
}

X
EDI after
8b 07 8b 4f ? 8b 57 ? 89 44 24 ? 89 4c 24 ? 89 54 24 ? e8

player_position_x + 0xc
玩家每次停止移动后触发一次
player_position_x = eax + 0x04
d9 58 ? d9 40 ? d9 58 ? d9 40 ? d9 58 ? 83 c4
fstp dword ptr [eax+10]
fld dword ptr [eax+08]

## 准心位置 x z y
<Description>"准心阻挡点坐标"</Description>
<VariableType>Float</VariableType>
<Address>rwr_game.exe+004fb4d4</Address>
<Offsets>
	<Offset>10</Offset>
	<Offset>1494</Offset>
	<Offset>8</Offset>
	<Offset>8</Offset>
	<Offset>2c</Offset>
	<Offset>24</Offset>
	<Offset>8</Offset>
</Offsets>
	

<Description>"准心瞄准投影坐标"</Description>
<VariableType>Float</VariableType>
<Address>rwr_game.exe+004fb4d4</Address>
<Offsets>
	<Offset>2c</Offset>
	<Offset>1494</Offset>
	<Offset>8</Offset>
	<Offset>8</Offset>
	<Offset>2c</Offset>
	<Offset>24</Offset>
	<Offset>8</Offset>
</Offsets>
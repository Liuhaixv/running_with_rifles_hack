#pragma once
#include "memory.hpp"
class Client {
public :
	Client(Memory memory) {
		this->memory = memory;
	}
	int get_crosshair_status() {
		/*
		no target:0
		yellow crosshair point(clear to shoot enemy):1
		red crosshair point(unable to hit aim-point):2
		not in game or dead:3 or 11

		rwr_game.exe+004FB4D4 -> 8 24 2c 8 8 1494 8
		*/
		DWORD offsetToGameBaseAdress = 0x004FB4D4;
		int crosshairStatusOffsets[] = { 0x8,0x24 ,0x2c ,0x8 ,0x8 ,0x1494 ,0x8 };

		DWORD crosshairStatusAddress = NULL;

		crosshairStatusAddress = memory.FindPointer(7,memory.gameBaseAddress + offsetToGameBaseAdress, crosshairStatusOffsets);

		int crosshair_status = memory.read_mem<int>(crosshairStatusAddress);
		return crosshair_status;
	}

	//use simulate mouse，may be replaced with writing memory method
	void shoot() {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下左键
		Sleep(20);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
	}

	//超大视野 0 -2.2 0.0000001
	void set_camera_angles(Vector3 angles) {

		DWORD offsetToGameBaseAdress = 0x4fb4d4;
		int offsets[] = { 0x8, 0x24, 0x2c, 0x8, 0x94, 0x3c};

		DWORD camera_angles_addr = memory.FindPointer(6, memory.gameBaseAddress + offsetToGameBaseAdress, offsets);

		memory.write_mem(camera_angles_addr, angles);
	}

	void teleport_to(Point point) {
		teleport_to(point.x, point.z, point.y);
	}

	void teleport_to(float x, float z, float y) {
		TwoPoint to_point = { x,z,y ,x,z,y};

		DWORD offsetToGameBaseAdress = 0x004FB4D4;
		int playerPositonPoint_Offsets[] = { 0x2c, 0x20 ,0x24 ,0x20, 0x0, 0x34, 0xD18, 0x4, 0xB4 ,0x4};

		DWORD playerPositionPoint_addr = memory.FindPointer(10, memory.gameBaseAddress + offsetToGameBaseAdress, playerPositonPoint_Offsets);

		memory.write_mem(playerPositionPoint_addr, to_point);
	}

	Point get_crosshair_position() {
		DWORD offsetToGameBaseAdress = 0x004FB4D4;
		int crosshairPositionOffsets[] = { 0x8,0x24 ,0x2c ,0x8 ,0x8 ,0x1494 ,0x28 };

		DWORD crosshairPosition_addr = memory.FindPointer(7, memory.gameBaseAddress + offsetToGameBaseAdress, crosshairPositionOffsets);

		Point crosshairPosition = memory.read_mem<Point>(crosshairPosition_addr);
		return crosshairPosition;
	}
private:
	Memory memory;
};
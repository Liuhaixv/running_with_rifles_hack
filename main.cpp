#pragma once
#include "client.hpp"

int main() {

	/*
	DWORD pID = NULL; // ID of our Game

	//get pid
	pID = get_porcId_by_name("rwr_game.exe");
	if (pID == NULL) {
		std::cout << "Launch the game before running hack!" << std::endl;
		return 0;
	}
	std::cout << pID << std::endl;


	HANDLE processHandle = NULL;
	processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
	if (processHandle == INVALID_HANDLE_VALUE || processHandle == NULL) { // error handling
		std::cout << "Failed to open process" << std::endl;
		return 0;
	}

	char gameName[] = "rwr_game.exe";
	DWORD gameBaseAddress = GetModuleBaseAddress(_T(gameName), pID);

	*/

	Memory memory;
	Client client(memory);

	//"UI"
	std::cout << "Running with rifles hack" << std::endl;

	bool LSHIFT_pressing = false;
	int last_aim_status = 0;
	while (true) {
		Sleep(2);
		int current_crosshair_status = client.get_crosshair_status();

		//Trigger Bot
		if (GetAsyncKeyState(VK_LMENU)) { // Left ALT			
			std::cout << "crosshair status: " << current_crosshair_status << std::endl;

			if (current_crosshair_status == 1) {
				client.shoot();
			}
		}

		//Teleport
		if (GetAsyncKeyState(VK_LSHIFT)) {
			client.teleport_to(client.get_crosshair_position());
			Sleep(5);
		}

		//Teleport player to invalid position when dead
		/*
		if (last_aim_status != 11 && current_crosshair_status == 11) {
			//Teleport
			std::cout << "Player dead, teleporting to invalid position" << std::endl;
			Point current_point = client.get_current_position();
			float offset = 100;
			client.teleport_to(Point{ current_point.x + offset, current_point.z, current_point.y + offset });
			Sleep(100);
		}
		*/

		/**/
		//random position
		if (GetAsyncKeyState(VK_SPACE)) {
			Point current_position = client.get_current_position();
			client.teleport_to(Point{ current_position.x+ 20 , current_position.z, current_position.y});
			Sleep(20);
			client.teleport_to(Point{ current_position.x, current_position.z, current_position.y });
			Sleep(20);
			client.teleport_to(Point{ current_position.x - 20 , current_position.z, current_position.y });
			Sleep(20);
			client.teleport_to(Point{ current_position.x, current_position.z, current_position.y });
			Sleep(20);
		}
		/**/

		//Change camera view
		//-0.15 -0.85 0.5
		static bool enabled_super_camera_view = false;
		if (GetAsyncKeyState(VK_INSERT)) {//Insert
			if (!enabled_super_camera_view) {
				client.set_camera_angles(Vector3{ 0, -2.2, 0.0000001});
				std::cout << "Setting camera angles to 0,-2.2,0.0000001" << std::endl;
				enabled_super_camera_view = true;
			}
			else {
				//改为默认相机视角
				client.set_camera_angles(Vector3{ -0.15, -0.85, 0.5});
				std::cout << "Setting camera angles to -0.15,-0.85,0.5" << std::endl;

				enabled_super_camera_view = false;
			}
			Sleep(200);
		}

		if (enabled_super_camera_view){
			if (GetAsyncKeyState(VK_PRIOR)) {//PAGE UP key
				Vector3 camera_angles = client.get_camera_angles();
				client.set_camera_angles(Vector3{ camera_angles.a,camera_angles.b -0.05F, camera_angles.c});
				Sleep(30);
			}else if (GetAsyncKeyState(VK_NEXT)) {//PAGE DOWN key
				Vector3 camera_angles = client.get_camera_angles();
				client.set_camera_angles(Vector3{ camera_angles.a,camera_angles.b + 0.05F, camera_angles.c });
				Sleep(30);
			}

		}

		last_aim_status = current_crosshair_status;
	}
}

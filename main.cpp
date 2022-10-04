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
	while (true) {
		Sleep(2);

		if (GetAsyncKeyState(VK_LMENU)) { // Left ALT
			int crosshair_status = client.get_crosshair_status();
			std::cout << "crosshair status: " <<  crosshair_status << std::endl;

			if (crosshair_status == 1) {
				client.shoot();
			}
		}

		if (GetAsyncKeyState(VK_LSHIFT)) {
			client.teleport_to(client.get_crosshair_position());
			Sleep(200);
		}
		
		/*if (GetAsyncKeyState(VK_LSHIFT)) {
			if (!LSHIFT_pressing) {
				client.teleport_to(client.get_crosshair_position());
				LSHIFT_pressing = true;
			}
		}
		else {
			LSHIFT_pressing = false;
		}*/
	}
}

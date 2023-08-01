#pragma once
#include "client.hpp"
#include <iomanip>
int main()
{

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

	// 禁用快速编辑模式
	{
		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
		DWORD prev_mode;

		// 获取当前控制台输入模式
		GetConsoleMode(hInput, &prev_mode);

		// 禁用快速编辑模式，同时保留其他标志位
		SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
	}

	//"UI"
	std::cout << "Running with rifles hack\n######################\nCreated by Liuhaixv\n######################\nhttps://github.com/Liuhaixv/running_with_rifles_hack\n######################\n" << std::endl;

	bool LSHIFT_pressing = false;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		BACKGROUND_GREEN
	);

	std::cout << std::setw(25) << std::left << "Left Alt " << "- TriggerBot" << std::endl;
	std::cout << std::setw(25) << std::left << "Left Shift " << "- Teleport" << std::endl;
	std::cout << std::setw(25) << std::left << "Insert " << "- Enable/Disable Zoom hack" << std::endl;
	std::cout << std::setw(25) << std::left << "Page Up / Page Down " << "- Increase/Decrease Zoom distance" << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(25) << std::left << "左Alt " << "- 自动扳机" << std::endl;
	std::cout << std::setw(25) << std::left << "左Shift " << "- 传送" << std::endl;
	std::cout << std::setw(25) << std::left << "Insert键 " << "- 激活调整相机高度功能" << std::endl;
	std::cout << std::setw(25) << std::left << "Page Up / Page Down键 " << "- 增加/减少 相机高度" << std::endl;

	while (true)
	{
		Sleep(2);

		// Trigger Bot
		if (GetAsyncKeyState(VK_LMENU))
		{ // Left ALT
			int crosshair_status = client.get_crosshair_status();
			//std::cout << "crosshair status: " << crosshair_status << std::endl;

			if (crosshair_status == 1)
			{
				client.shoot();
			}
		}

		// Teleport
		if (GetAsyncKeyState(VK_LSHIFT))
		{
			client.teleport_to(client.get_crosshair_position());
			Sleep(5);
		}

		// Change camera view
		//-0.15 -0.85 0.5
		static bool enabled_super_camera_view = false;
		if (GetAsyncKeyState(VK_INSERT))
		{ // Insert
			if (!enabled_super_camera_view)
			{
				client.set_camera_angles(Vector3{0, -2.2, 0.0000001});
				//std::cout << "Setting camera angles to 0,-2.2,0.0000001" << std::endl;
				enabled_super_camera_view = true;
			}
			else
			{
				//改为默认相机视角
				client.set_camera_angles(Vector3{-0.15, -0.85, 0.5});
				//std::cout << "正在设置相机视角\n"<<"Setting camera angles to -0.15,-0.85,0.5" << std::endl;

				enabled_super_camera_view = false;
			}
			Sleep(200);
		}

		if (enabled_super_camera_view)
		{
			if (GetAsyncKeyState(VK_PRIOR))
			{ // PAGE UP key
				Vector3 camera_angles = client.get_camera_angles();
				client.set_camera_angles(Vector3{camera_angles.a, camera_angles.b - 0.05F, camera_angles.c});
				Sleep(30);
			}
			else if (GetAsyncKeyState(VK_NEXT))
			{ // PAGE DOWN key
				Vector3 camera_angles = client.get_camera_angles();
				client.set_camera_angles(Vector3{camera_angles.a, camera_angles.b + 0.05F, camera_angles.c});
				Sleep(30);
			}
		}
	}
}

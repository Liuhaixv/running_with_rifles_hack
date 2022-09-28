#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> // _tcscmp
#include <vector>


DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
	DWORD dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
	MODULEENTRY32 ModuleEntry32 = { 0 };
	ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
	{
		do {
			if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
			{
				dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
				break;
			}
		} while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


	}
	CloseHandle(hSnapshot);
	return dwModuleBaseAddress;
}

static DWORD get_porcId_by_name(const std::string_view targetProcess) {
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				if (!targetProcess.compare(procEntry.szExeFile))
				{
					procId = procEntry.th32ProcessID;
					//std::cout << "found pID:" << procId << std::endl;
					//break;
				}
			} while (Process32Next(hSnap, &procEntry));
		}
	}
	CloseHandle(hSnap);

	return procId;
}

int get_crosshair_status(HANDLE handle, DWORD gameBaseAddress) {
	/*
	no target:0
	yellow crosshair point(clear to shoot enemy):1
	red crosshair point(unable to hit aim-point):2
	not in game or dead:3 or 11

	rwr_game.exe+004FB4D4 -> 8 24 2c 8 8 1494 8
	*/
	DWORD offsetGameToBaseAdress = 0x004FB4D4;
	std::vector<DWORD> crosshairStatusOffsets{ 0x8,0x24 ,0x2c ,0x8 ,0x8 ,0x1494 ,0x8 };

	DWORD baseAddress = NULL;

	//Get value at gamebase+offset -> store it in baseAddress
	ReadProcessMemory(handle, (LPVOID)(gameBaseAddress + offsetGameToBaseAdress), &baseAddress, sizeof(baseAddress), NULL);

	std::cout << "debugginfo: baseaddress = " << std::hex << baseAddress << std::endl;
	DWORD crosshairStatusAddress = baseAddress; //the Adress we need -> change now while going through offsets
	for (int i = 0; i < crosshairStatusOffsets.size() - 1; i++) // -1 because we dont want the value at the last offset
	{
		ReadProcessMemory(handle, (LPVOID)(crosshairStatusAddress + crosshairStatusOffsets.at(i)), &crosshairStatusAddress, sizeof(crosshairStatusAddress), NULL);
		std::cout << "debugginfo: Value at offset = " << std::hex << crosshairStatusAddress << std::endl;
	}

	crosshairStatusAddress += crosshairStatusOffsets.at(crosshairStatusOffsets.size() - 1); //Add Last offset -> done!

	std::cout << "debugginfo: Real Value Address = " << std::hex << crosshairStatusAddress << std::endl;


	int crosshair_status = -1;
	ReadProcessMemory(handle, (LPVOID)(crosshairStatusAddress), &crosshair_status, sizeof(int), NULL);
	return crosshair_status;
}

//use simulate mouse£¬may be replaced with writing memory method
void shoot(HANDLE handle, DWORD gameBaseAddress) {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//°´ÏÂ×ó¼ü
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//ËÉ¿ª×ó¼ü
}

int main() {

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

	

	//"UI"
	std::cout << "Running with rifles hack" << std::endl;
	while (true) {
		Sleep(2);

		if (GetAsyncKeyState(VK_LMENU)) { // Left ALT
			int crosshair_status = get_crosshair_status(processHandle, gameBaseAddress);
			std::cout << "crosshair status: " << crosshair_status << std::endl;

			if (crosshair_status == 1) {
				shoot(processHandle, gameBaseAddress);
			}
		}
	}
}

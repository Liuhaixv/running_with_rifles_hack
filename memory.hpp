#pragma once
#include <Windows.h>
#include<TlHelp32.h>
#include <iostream>
#include <tchar.h> // _tcscmp
#include <vector>


class Memory {
public:
	DWORD pID = NULL;
	HANDLE processHandle = NULL;
	DWORD gameBaseAddress = NULL;

	Memory() {

		pID = get_porcId_by_name("rwr_game.exe");
		if (pID == NULL) {
			std::cout << "Please Launch the game before running this debug tool!" << std::endl;
			return;
		}
		std::cout << pID << std::endl;

		processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
		if (processHandle == INVALID_HANDLE_VALUE || processHandle == NULL) { // error handling
			std::cout << "Failed to open process" << std::endl;
			return;
		}

		char gameName[] = "rwr_game.exe";
		gameBaseAddress = GetModuleBaseAddress(_T(gameName), pID);
	}

	template <typename var>
	bool write_mem(DWORD address, var value) {
		return WriteProcessMemory(processHandle, (LPVOID)address, &value, sizeof(var), NULL);
	}

	template <typename var>
	var read_mem(DWORD address) {
		var value;
		ReadProcessMemory(processHandle, (LPCVOID)address, &value, sizeof(var), NULL);
		return value;
	}

	DWORD FindPointer(int offset, DWORD baseaddr, int offsets[])
	{
		DWORD Address = baseaddr;
		int total = offset;
		for (int i = 0; i < total; i++) //Loop trough the offsets
		{
			ReadProcessMemory(processHandle, (LPCVOID)Address, &Address, sizeof(DWORD), NULL);
			Address += offsets[i];
		}
		return Address;
	}
private:

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
};

struct Vector3 {
	float a;
	float b;
	float c;
};

struct Point {
	float x;
	float z;
	float y;
};

struct TwoPoint {
	float x1;
	float z1;
	float y1;
	float x2;
	float z2;
	float y2;
};
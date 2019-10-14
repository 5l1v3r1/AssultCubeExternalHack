// AssultCubeExternalHack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include "mem.h"

int main()
{
	HANDLE hProcess = nullptr;
	uintptr_t
		moduleBase = 0,
		localPlayerPtr = 0,
		healthAddr = 0,
		rifleAmmoAddr = 0,
		pistalAmmoAddr = 0,
		grenadeAddr = 0;


	bool healthSwitch = false;
	bool rifleAmmoSwitch = false;
	bool pistalAmmoSwitch = false;
	bool grenadeSwitch = false;



	const int newValue = 1337;

	DWORD procId = GetProcId(L"ac_client.exe");

	if (procId)
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);
		moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");
		localPlayerPtr = moduleBase + 0x10F4F4;
		healthAddr = FindDMAAddy(hProcess, localPlayerPtr, {0xf8});
		rifleAmmoAddr = FindDMAAddy(hProcess, localPlayerPtr, {0x150});
		pistalAmmoAddr = FindDMAAddy(hProcess, localPlayerPtr, {0x13c});
		grenadeAddr = FindDMAAddy(hProcess, localPlayerPtr, {0x158});
	}else
	{
		std::cout << "Process not found, press enter to exit\n";
		getchar();
		return 0;
	}



	DWORD dwExit = 0;

	while (GetExitCodeProcess(hProcess, &dwExit) && dwExit == STILL_ACTIVE)
	{
		
		if(GetAsyncKeyState(VK_NUMPAD1) & 1)
		{
			healthSwitch = !healthSwitch;
			if(healthSwitch)
			{
				WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newValue, sizeof(int), nullptr);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD2) & 1)
		{
			rifleAmmoSwitch = !rifleAmmoSwitch;
			if (rifleAmmoSwitch)
			{
				WriteProcessMemory(hProcess, (BYTE*)rifleAmmoAddr, &newValue, sizeof(int), nullptr);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD3) & 1)
		{
			pistalAmmoSwitch = !pistalAmmoSwitch;
			if (pistalAmmoSwitch)
			{
				WriteProcessMemory(hProcess, (BYTE*)pistalAmmoAddr, &newValue, sizeof(int), nullptr);
			}
		}

		if (GetAsyncKeyState(VK_NUMPAD4) & 1)
		{
			grenadeSwitch = !grenadeSwitch;
			if (grenadeSwitch)
			{
				WriteProcessMemory(hProcess, (BYTE*)grenadeAddr, &newValue, sizeof(int), nullptr);
			}
		}


		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			return 0;
		}


		Sleep(10);


	}
	std::cout << "Process not found, press enter to exit\n";


}

// AssultCubeExternalHack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"


int main()
{
	// Get processId of target process
	DWORD procId = GetProcId(L"ac_client.exe");

	// GetModuleBaseAddress
	uintptr_t moduleBase = GetModuleBaseAddress(procId, L"ac_client.exe");

	// Get handle to process
	HANDLE hProcess = nullptr;
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	// Resolve base address of the point
	uintptr_t dynamicPointerBaseAddress = moduleBase + 0x10F4F4;
	std::cout << "DynamicPointerBaseAddress = " << "0x" << std::hex << dynamicPointerBaseAddress << std::endl;


	while (true)
	{
		// resolve offset of hack
		std::vector<unsigned int> healthOffsets = {0xf8};
		uintptr_t healthAddr = FindDMAAddy(hProcess, dynamicPointerBaseAddress, healthOffsets);
		std::cout << "healthAddr = " << "0x" << std::hex << healthAddr << std::endl;
		// RPM
		int healthValue = 0;
		ReadProcessMemory(hProcess, (BYTE*)healthAddr, &healthValue, sizeof(healthValue), nullptr);
		std::cout << "Current Health value = " << std::dec << healthValue << std::endl;
		// WPM
		int newHealth = 100;
		WriteProcessMemory(hProcess, (BYTE*)healthAddr, &newHealth, sizeof(int), nullptr);


		//------------------------------------------------------------

		// resolve offset of hack
		std::vector<unsigned int> rifleOffsets = {0x150};
		uintptr_t rifleAddr = FindDMAAddy(hProcess, dynamicPointerBaseAddress, rifleOffsets);
		std::cout << "rifleAddr = " << "0x" << std::hex << rifleAddr << std::endl;
		// RPM
		int rifleValue = 0;
		ReadProcessMemory(hProcess, (BYTE*)rifleValue, &rifleValue, sizeof(rifleValue), nullptr);
		std::cout << "Current Rifle value = " << std::dec << rifleValue << std::endl;
		// WPM
		int newRifle = 100;
		WriteProcessMemory(hProcess, (BYTE*)rifleAddr, &newRifle, sizeof(int), nullptr);




		// resolve offset of hack
		std::vector<unsigned int> granadeOffsets = {0x158};
		uintptr_t granadeAddr = FindDMAAddy(hProcess, dynamicPointerBaseAddress, granadeOffsets);
		std::cout << "granadeAddr = " << "0x" << std::hex << granadeAddr << std::endl;
		// RPM
		int granadeValue = 0;
		ReadProcessMemory(hProcess, (BYTE*)granadeValue, &granadeValue, sizeof(int), nullptr);
		std::cout << "Current Granade value = " << std::dec << granadeValue << std::endl;
		// WPM
		int newGranade = 100;
		WriteProcessMemory(hProcess, (BYTE*)granadeAddr, &newGranade, sizeof(int), nullptr);





		// resolve offset of hack
		std::vector<unsigned int> pistalOffsets = { 0x13c };
		uintptr_t pistalAddr = FindDMAAddy(hProcess, dynamicPointerBaseAddress, pistalOffsets);
		std::cout << "pistalAddr = " << "0x" << std::hex << pistalAddr << std::endl;
		// RPM
		int pistalValue = 0;
		ReadProcessMemory(hProcess, (BYTE*)pistalValue, &pistalValue, sizeof(int), nullptr);
		std::cout << "Current Pistal value = " << std::dec << pistalValue << std::endl;
		// WPM
		int newPistal = 100;
		WriteProcessMemory(hProcess, (BYTE*)pistalAddr, &newPistal, sizeof(int), nullptr);
	}
}

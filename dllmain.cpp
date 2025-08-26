#include "ASM/SendPacket.h"
#include "ASM/ShowGameMessage.h"
#include <windows.h>
DWORD WINAPI FunctionDemonstration(LPVOID lpParam) {
    BYTE leave[4] = {0x00, 0x20, 0xFF, 0xFF};

    while (true) {
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            SendPacket(&leave[0]);
            Sleep(2000);
            ShowGameMessage(5, 2, "Leaving room...");
        }
        Sleep(50);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, FunctionDemonstration, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

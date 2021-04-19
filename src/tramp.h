#ifndef TRAMP_H
#define TRAMP_H
#include <Windows.h>

// Detour credit below
// https://guidedhacking.com/threads/c-detour-hooking-function-tutorial.7930/
// https://guidedhacking.com/threads/simple-x86-c-trampoline-hook.14188/

bool detour(void* a, void* b)
{
    int length = 10;
    DWORD curProtection;
    VirtualProtect(a, length, PAGE_EXECUTE_READWRITE, &curProtection);

    memset(a, 0x90, length);

    uintptr_t relativeAddress = ((uintptr_t)b - (uintptr_t)a) - 5;

    *(BYTE*)a = 0xE9;
    *(uintptr_t*)((uintptr_t)a + 1) = relativeAddress;

    DWORD temp;
    VirtualProtect(a, length, curProtection, &temp);

    return true;
}

char* tramp(char* a, char* b)
{
    int length = 10;
    void* gateway = VirtualAlloc(0, length + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    memcpy(gateway, a, length);

    intptr_t  gatewayRelativeAddr = ((intptr_t)a - (intptr_t)gateway) - 5;
    *(char*)((intptr_t)gateway + length) = 0xE9;
    *(intptr_t*)((intptr_t)gateway + length + 1) = gatewayRelativeAddr;

    detour(a, b);

    return (char*)gateway;
}

#endif //PCH_H
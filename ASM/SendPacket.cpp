#include "SendPacket.h"

void SendPacket(BYTE *payload) {
    DWORD *payloadAddress = (DWORD *)0x006e3e28;
    DWORD *sendPacketFunc = (DWORD *)0x004c16a0;

    memcpy((DWORD *)(*payloadAddress + 0xa4), payload, sizeof(payload) + 4);
    *PWORD(*PDWORD(payloadAddress) + 0x40a0) = sizeof(payload) + 4;

    __asm {
          pushad
          mov esi, [payloadAddress]
          mov esi, [esi]
          lea ecx, [esi + 0x80c8]
          popad
          mov ecx, [payloadAddress]
          mov ecx, [ecx]
          mov[ebp - 4], ecx
          mov ecx, [sendPacketFunc]
          mov[ebp - 8], ecx
          push[ebp - 4]
          call dword ptr[ebp - 8]
    }
}
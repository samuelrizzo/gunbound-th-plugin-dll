#include "ShowGameMessage.h"

DWORD showGameMessageAddressFunc1 = 0x0044A230;
DWORD showGameMessageAddressFunc2 = 0x00527860;

void ShowGameMessage(int icon, int color, const char *message) {
    __try {
        __asm {
            push icon
            push color
            push message
            call showGameMessageAddressFunc1

            push icon
            push color
            push message    
            call showGameMessageAddressFunc2
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
}
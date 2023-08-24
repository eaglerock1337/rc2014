#include <stdio.h>
#include <string.h>

#include "text.h"

/***************************************
* TMSim - Text management module
***************************************/

void tmprint(char* str, uint8_t type) {
    for (uint8_t i = 0; i < strlen(str); i++) {
        putc(str[i], stdout);
        fflush(stdout);         // flush stdout buffer
        delay(delays[type]);
    }
}

// needs tweaking
void delay(uint16_t length) {
    for (uint16_t i = 0; i < length; i++) {
        for (uint16_t j = 0; j < DELAYLOOP; j++);
    }
}

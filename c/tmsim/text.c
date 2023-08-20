#include <stdio.h>
#include <string.h>

#include "text.h"

/***************************************
* TMSim - Text management module
***************************************/

void tmprint(char* str, uint8_t type) {
    
}

// needs tweaking
void delay(uint16_t length) {
    const uint16_t max = 65535;
    for (uint16_t i = 0; i < length; i++) {
        for (uint16_t j = 0; j < max; j++);
    }
}
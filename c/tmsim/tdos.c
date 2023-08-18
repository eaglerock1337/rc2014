#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "tdos.h"
#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system module
***************************************/

const char command_list[][9] = {
    "sensors",
    "status",
    "help",
    "calculate",
    "shutdown",
    "lookaway",
    "emergency",
    "inventory",
    "player",
    "shield",
    "move"
};

void tdos_command_loop(struct time_machine* tm, struct player* p) {
    printf("Cow goes moo.\n");
}

void boot(struct time_machine* tm) {
    
}
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
    printf("TDOS|%s|>", print_tm_status(tm));
    char* command;
    scanf("%s", &command);
}

void boot(struct time_machine* tm) {
    printf("Cow goes boot.\n");
}
#include <stdint.h>

#include "tdos.h"
#include "text.h"
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
    // add logic here to determine the speed of the terminal output
    uint8_t speed = NORM_TDOS;
    do {
        tmprint(format("TDOS|%s|>", *print_tm_status(tm)), speed);
        char* command;
        scanf("%s", &command);
        tmprint(format("You entered %s", *command), speed);
    } while (true);
}

void boot(struct time_machine* tm) {
    printf("Cow goes boot.\n");
}
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "tdos.h"
#include "text.h"
#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system module
***************************************/

const char command_list[][10] = {
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
    // TODO: add chance for system to reset (once a reset operation is created)
    // TODO: add logic here to determine the speed of the terminal output
    uint8_t speed = NORM_TDOS;
    do {
        refresh_part_status(tm);
        refresh_power_data(tm);
        tmprint("TDOS|", speed);
        printf("%i", tm->tm_status);
        tmprint(status_disp(tm->tm_status), speed);
        tmprint("|> ", speed);
        char command[20];
        scanf("%s", command);
        tmprint("You entered ", speed);
        tmprint(command, speed);
        tmprint("\n", speed);
    } while (true);
}

void printdos(char* str, struct time_machine* tm) {
    switch(tm->status.computer) {
    case NOM: tmprint(str, FAST_TDOS);  return;
    case INF: tmprint(str, NORM_TDOS);  return;
    case WRN: tmprint(str, SLOW_TDOS);  return;
    default: printf("Something went wrong in printdos()\n");
    }
}

bool boot(struct time_machine* tm) {
    tmprint("Starting TDOS boot ROM for RC2014...\n\n", SLOW_TDOS);
    delay(4096);
    tmprint("ROM loaded successfully. Starting\n", SLOW_TDOS);
    tmprint("TDOS system health checks:\n\n", SLOW_TDOS);
    delay(2048);
    uint8_t worst_val = 0;
    for (int i = 0; i < 6; i++) {
        printf("%i %i", tm->parts.computer[i].wear, tm->parts.computer[i].tear);
        uint8_t val = get_condition(&tm->parts.computer[i]);
        worst_val = (val > worst_val) ? val : worst_val;
        tmprint(get_computer_part(i), SLOW_TDOS);
        tmprint(": ", SLOW_TDOS);
        tmprint(status_disp(get_part_status(val)), SLOW_TDOS);
        tmprint("\n", SLOW_TDOS);
    }
    tmprint("\nOverall system status: ", SLOW_TDOS);
    tmprint(status_disp(get_part_status(worst_val)), SLOW_TDOS);
    tmprint("\n", SLOW_TDOS);
    tm->status.computer = get_part_status(worst_val);
    switch (tm->status.computer) {
    case NOM: tmprint("Running at turbo clock speed.\n\n", FAST_TDOS);   break;
    case INF: tmprint("Running at normal clock speed.\n\n", NORM_TDOS);  break;
    case WRN: tmprint("Running at safe clock speed.\n\n", SLOW_TDOS);  break;
    case FLT: tmprint("System in critical condition. Halting.\n\n", SLOW_TDOS);
              return false; break;
    default: printf("Something went wrong in boot()\n");
    }
    return true;
}

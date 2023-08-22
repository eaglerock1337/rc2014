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
        tmprint("TDOS|", speed);
        tmprint(statusdisp(tm->tm_status), speed);
        tmprint("|> ", speed);
        char* command;
        scanf("%s", command);
        tmprint("You entered ", speed);
        tmprint(command, speed);
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
    tmprint("ROM loaded successfully. Starting TDOS\n", SLOW_TDOS);
    tmprint("system preflight health checks:\n\n", SLOW_TDOS);
    uint8_t lowest_val = 0;
    for (int i = 0; i < 6; i++) {
        uint8_t val = get_condition(&tm->parts.computer[i]);
        val = (val < lowest_val) ? lowest_val : val;
        tmprint(get_computer_part(i) + ':' + ' ', SLOW_TDOS);
        tmprint(statusdisp(val) + '\n', SLOW_TDOS);
    }
    tmprint("\nOverall system status: ", SLOW_TDOS);
    tmprint(statusdisp(lowest_val) + '\n', SLOW_TDOS);
    tm->status.computer = lowest_val;
    switch (lowest_val) {
    case NOM: tmprint("System at turbo clock speed.\n\n", FAST_TDOS);   break;
    case INF: tmprint("System at normal clock speed.\n\n", NORM_TDOS);  break;
    case WRN: tmprint("System at safety clock speed.\n\n", SLOW_TDOS);  break;
    case FLT: tmprint("System in critical condition. Halting.\n\n", SLOW_TDOS);
              return false; break;
    default: printf("Something went wrong in boot()\n");
    }
    return true;
}

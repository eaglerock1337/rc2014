#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "tdos.h"
#include "text.h"
#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system module
***************************************/

void tdos_command_loop(struct time_machine* tm, struct player* p) {
    // TODO: add chance for system to reset (once a reset operation is created)
    uint8_t speed = tm->status.computer;
    do {
        refresh_part_status(tm);
        refresh_power_data(tm);
        snprintf(print, PRINT_BUF, "TDOS|%s|> ", status_disp(tm->tm_status));
        printdos(print, speed);         // string print buffer
        // TODO: proper scan function that sanitizes character input
        scanf("%s", cmd);
        snprintf(print, PRINT_BUF, "\nYou entered %s.\n", cmd);
        printdos(print, speed);
    } while (true);
}

int check_cmd(char *s) {
	/* New function -- compares s to scaned citem and returns true if it
	   matches to the length of s */
	// return strncmp(s, citem, max(1, strlen(citem))) == 0;
    return 0;
}

void printarr(char* strarr[], uint8_t speed) {
    // TODO: figure out a better way to do printing through the tmprint routine
    for (int i = 0; i < sizeof(*strarr)/sizeof(*strarr[0]); i++) {
        printdos(strarr[i], speed);
    }
}

void printdos(char* str, uint8_t speed) {
    switch(speed) {
    case NOM: tmprint(str, FAST_TDOS);  return;
    case INF: tmprint(str, NORM_TDOS);  return;
    case WRN: tmprint(str, SLOW_TDOS);  return;
    default: printf("Something went wrong in printdos()\n");
    }
}

bool boot(struct time_machine* tm) {
    refresh_power_data(tm);
    refresh_part_status(tm);
    tmprint("Starting TDOS boot ROM for RC2014...\n", SLOW_TDOS);
    delay(4096);
    tmprint("\nROM loaded successfully. Starting\n", SLOW_TDOS);
    tmprint("TDOS system health checks:\n", SLOW_TDOS);
    delay(2048);
    tmprint("\n", SLOW_TDOS);
    uint8_t worst_val = 0;
    for (int i = 0; i < 6; i++) {
        uint8_t val = get_condition(&tm->parts.computer[i]);
        worst_val = (val > worst_val) ? val : worst_val;
        snprintf(print, PRINT_BUF, "%20s- %s\n", get_computer_part(i), status_disp(get_part_status(val)));
        tmprint(print, SLOW_TDOS);      // string formatting buffer
        delay(512);
    }
    snprintf(print, PRINT_BUF, "Overall system status- %s\n", status_disp(get_part_status(worst_val)));
    tmprint(print, SLOW_TDOS);          // string formatting buffer
    delay(1024);
    tm->status.computer = get_part_status(worst_val);
    switch (tm->status.computer) {
    case NOM: tmprint("Running at full clock speed.\n\n", FAST_TDOS);   break;
    case INF: tmprint("Running at normal clock speed.\n\n", NORM_TDOS);  break;
    case WRN: tmprint("Running at safe clock speed.\n\n", SLOW_TDOS);  break;
    case FLT: tmprint("System in critical condition. Halting.\n\n", SLOW_TDOS);
              return false; break;
    default: printf("Something went wrong in boot()\n");
    }
    return true;
}

/***** tdos command functions *****/

#ifdef DEBUG
bool debug_me(struct time_machine* tm, struct player* p) {
    printf("Debug stuff goes here.\n");

}
#endif
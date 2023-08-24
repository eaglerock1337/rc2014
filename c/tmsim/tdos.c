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
        uint8_t cmd_id = check_cmd(cmd);
        switch (cmd_id) {
        case CMD_STATUS:    cmd_status(tm, p);      break;
        case CMD_LOOKAWAY:  cmd_lookaway(tm, p);    break;
        case CMD_DATE:      cmd_date(tm, p);        break;
        case CMD_SENSORS:   cmd_sensors(tm, p);     break;
        case CMD_HELP:      cmd_help(tm, p);        break;
        case CMD_CALCULATE: cmd_calculate(tm, p);   break;
        case CMD_EMERGENCY: cmd_emergency(tm, p);   break;
        case CMD_INVENTORY: cmd_inventory(tm, p);   break;
        case CMD_PLAYER:    cmd_player(tm, p);      break;
        case CMD_SHIELD:    cmd_shield(tm, p);      break;
        case CMD_MOVE:      cmd_move(tm, p);        break;
        case CMD_REPORT:    cmd_report(tm, p);      break;
        case CMD_EXIT:      cmd_exit(tm, p);        break;
        case CMD_ERROR:     cmd_error(tm);          break;
        case CMD_NULL:      cmd_null(tm);           break;
#ifdef DEBUG
        case CMD_REROLL:    cmd_reroll(tm, p);      break;
        case CMD_DEBUG:     cmd_debug(tm, p);       break;
#endif
        default:    printf("Something went wrong in tdos_command_loop()\n");
        }

        snprintf(print, PRINT_BUF, "\nYou entered %s.\n", cmd);
        printdos(print, speed);
    } while (true);
}

uint8_t check_cmd(char *s) {
	/* New function -- compares s to scaned citem and returns true if it
	   matches to the length of s */
	// return strncmp(s, citem, max(1, strlen(citem))) == 0;
    // TODO: this function
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

void cmd_status(struct time_machine* tm, struct player* p) {
    printdos("status goes moo.\n", tm->status.computer);
}

void cmd_lookaway(struct time_machine* tm, struct player* p) {
    printdos("lookaway goes moo.\n", tm->status.computer);
}

void cmd_date(struct time_machine* tm, struct player* p) {
    printdos("date goes moo.\n", tm->status.computer);
}

void cmd_sensors(struct time_machine* tm, struct player* p) {
    printdos("sensors goes moo.\n", tm->status.computer);
}

void cmd_help(struct time_machine* tm, struct player* p) {
    printdos("help goes moo.\n", tm->status.computer);
}

void cmd_calculate(struct time_machine* tm, struct player* p) {
    printdos("calculate goes moo.\n", tm->status.computer);
}

void cmd_emergency(struct time_machine* tm, struct player* p) {
    printdos("emergency goes moo.\n", tm->status.computer);
}

void cmd_inventory(struct time_machine* tm, struct player* p) {
    printdos("inventory goes moo.\n", tm->status.computer);
}

void cmd_player(struct time_machine* tm, struct player* p) {
    printdos("player goes moo.\n", tm->status.computer);
}

void cmd_shield(struct time_machine* tm, struct player* p) {
    printdos("shield goes moo.\n", tm->status.computer);
}

void cmd_move(struct time_machine* tm, struct player* p) {
    printdos("move goes moo.\n", tm->status.computer);
}

void cmd_report(struct time_machine* tm, struct player* p) {
    printdos("report goes moo.\n", tm->status.computer);
}

void cmd_exit(struct time_machine* tm, struct player* p) {
    printdos("exit goes moo.\n", tm->status.computer);
}

void cmd_error(struct time_machine* tm) {
    printdos("error goes moo.\n", tm->status.computer);
}

void cmd_null(struct time_machine* tm) {
    printdos("null goes moo.\n", tm->status.computer);
}

#ifdef DEBUG
void cmd_reroll(struct time_machine* tm, struct player* p) {
    printdos("reroll goes moo.\n", tm->status.computer);
}

void cmd_debug(struct time_machine* tm, struct player* p) {
    printdos("debug goes moo.\n", tm->status.computer);
}
#endif
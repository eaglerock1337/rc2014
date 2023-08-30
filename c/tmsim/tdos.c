#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "sim.h"
#include "tdos.h"
#include "text.h"
#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system module
***************************************/

void tdos_command_loop(struct time_machine* tm, struct player* p) {
    // TODO: add chance for system to reset (once a reset operation is created)
    do {
        refresh_part_status(tm);
        refresh_power_data(tm);
        snprintf(print, PRINT_BUF, "TDOS|%s|> ", status_disp(tm->tm_status));
        printdos(print, tm->status.computer);       // string print buffer
        // TODO: proper scan function that sanitizes character input
        scanf("%s", cmd);
#ifdef RC
        // this is way easier than dealing with C compiler pragmas
        printdos("\n", tm->status.computer);
#endif
        uint8_t cmd_id = check_cmd(cmd);
        switch (cmd_id) {
        case CMD_STATUS:        cmd_status(tm, p);      break;
        case CMD_LOOKAWAY:      cmd_lookaway(tm, p);    return;
        case CMD_DATE:          cmd_date(tm, p);        break;
        case CMD_SENSORS:       cmd_sensors(tm, p);     break;
        case CMD_HELP:          cmd_help(tm, p);        break;
        case CMD_CIRCUITS:      cmd_circuits(tm, p);    break;
        case CMD_CALCULATE:     cmd_calculate(tm, p);   break;
        case CMD_INVENTORY:     cmd_inventory(tm, p);   break;
        case CMD_PLAYER:        cmd_player(tm, p);      break;
        case CMD_SHIELD:        cmd_shield(tm, p);      break;
        case CMD_MOVE:          cmd_move(tm, p);        break;
        case CMD_REPORT:        cmd_report(tm, p);      break;
        case CMD_ODDS:          cmd_odds(tm, p);        break;
        case CMD_TRAVEL:        cmd_travel(tm, p);      break;
        case CMD_EXIT:          cmd_exit(tm, p);        return;
        case CMD_EMERGENCY:     cmd_emergency(tm, p);   break;
        case CMD_ERROR:         cmd_error(tm);          break;
        case CMD_NULL:          cmd_null(tm);           break;
#ifdef DEBUG
        case CMD_REROLL:        cmd_reroll(tm, p);      break;
        case CMD_DEBUG:         cmd_debug(tm, p);       break;
#endif
        default:    printf("Something went wrong in tdos_command_loop()\n");
        }
    } while (true);
}

uint8_t check_cmd(char *s) {
    if (strlen(s) == 0) { return CMD_NULL; }

    // normal command list
    for (uint8_t i = 0; i < TOTAL_CMD; i++) {
        if (strncmp(cmd_list[i], s, strlen(s)) == 0) {
            return i;
        }        
    }

    // protected command list
    for (uint8_t i = 0; i < TOTAL_PROTEC; i++) {
        if (strncmp(cmd_protec[i], s, strlen(cmd_protec[i])) == 0) {
            return i + CMD_LOOKAWAY;
        }        
    }

    // debug command list
#ifdef DEBUG
    for (uint8_t i = 0; i < TOTAL_DEBUG; i++) {
        if (strncmp(debug_list[i], s, strlen(debug_list[i])) == 0) {
            return i + CMD_DEBUG;
        }
    }
#endif
	return CMD_ERROR;
}

void printdos(char* str, uint8_t speed) {
    switch(speed) {
    case NOM: tmprint(str, FAST_TDOS);  return;
    case INF: tmprint(str, NORM_TDOS);  return;
    case WRN: tmprint(str, SLOW_TDOS);  return;
    default: printf("Something went wrong in printdos()\n");
    }
}

bool cold_boot(struct time_machine* tm) {
    refresh_power_data(tm);
    refresh_part_status(tm);
    tmprint("Starting TDOS bootstrapper for RC2014...\n", SLOW_TDOS);
    delay(4096);
    tmprint("\nROM loaded successfully. Starting "
            "TDOS system health checks:\n", SLOW_TDOS);
    delay(2048);
    tmprint("\n", SLOW_TDOS);
    uint8_t worst_val = 0;
    for (int i = 0; i < 6; i++) {
        uint8_t val = get_condition(&tm->parts.computer[i]);
        worst_val = (val > worst_val) ? val : worst_val;
        snprintf(print, PRINT_BUF, "%-20s- %s\n", get_computer_part(i),
                 status_disp(get_part_status(val)));
        tmprint(print, SLOW_TDOS);      // string formatting buffer
        delay(1024);
    }
    snprintf(print, PRINT_BUF, "Minimum Part Status - %s\n",
             status_disp(get_part_status(worst_val)));
    tmprint(print, SLOW_TDOS);          // string formatting buffer
    delay(2048);
    tm->status.computer = get_part_status(worst_val);
    switch (tm->status.computer) {
    case NOM: tmprint("Running at full clock speed.\n", FAST_TDOS); break;
    case INF: tmprint("Running at normal clock speed.\n", NORM_TDOS); break;
    case WRN: tmprint("Running at safe clock speed.\n", SLOW_TDOS); break;
    case FLT: tmprint("System in critical condition. Halting.\n\n", SLOW_TDOS); return false;
    default: printf("Something went wrong in boot()\n");
    }
    warm_boot(tm);
    return true;
}

void warm_boot(struct time_machine* tm) {
    printdos("\nStarting Temporal Displacement Operating System\n", tm->status.computer);
    snprintf(print, PRINT_BUF, "    Version %s compiled on %s...\n\n", VERSION, COMPILED);
    printdos(print, tm->status.computer);       // string buffer
    delay(4096);
    // TODO: more here later
    // printdos("\n", tm->status.computer);
}

/***** tdos normal command functions *****/

void cmd_status(struct time_machine* tm, struct player* p) {
    printdos("status goes moo.\n", tm->status.computer);
}

void cmd_date(struct time_machine* tm, struct player* p) {
    printdos("date goes moo.\n", tm->status.computer);
}

void cmd_sensors(struct time_machine* tm, struct player* p) {
    printdos("sensors goes moo.\n", tm->status.computer);
}

void cmd_help(struct time_machine* tm, struct player* p) {
    // TODO: add sarcasm (use a help_count variable?)
    printdos("==== The following commands are available:\n", tm->status.computer);
    uint8_t rows = floor(TOTAL_CMD / 4);        // all complete rows
    uint8_t rem = TOTAL_CMD % 4;                // final incomplete row
    for (int i = 0; i < rows; i++) {
        snprintf(print, PRINT_BUF, "%-9s %-9s %-9s %-9s\n",
                 cmd_list[i*4], cmd_list[i*4 + 1], 
                 cmd_list[i*4 + 2], cmd_list[i*4 + 3]);
        printdos(print, tm->status.computer);
    }
    for (int i = 4 * rows; i < 4 * rows + rem; i++) {
        snprintf(print, PRINT_BUF, "%-9s ", cmd_list[i]);
        printdos(print, tm->status.computer);
    }
    printdos("-- These commands can be abbreviated (e.g. 'sen' or 'ca').\n", tm->status.computer);

    // TODO: don't use pointer fuckery to print out the debug commands
    printdos("\n==== The following protected commands are available:\n", tm->status.computer);
    rows = floor((TOTAL_PROTEC + TOTAL_DEBUG) / 4);   // all complete rows
    rem = (TOTAL_PROTEC + TOTAL_DEBUG) % 4;           // final incomplete row
    for (int i = 0; i < rows; i++) {
        snprintf(print, PRINT_BUF, "%-9s %-9s %-9s %-9s\n",
                 cmd_protec[i*4], cmd_protec[i*4 + 1], 
                 cmd_protec[i*4 + 2], cmd_protec[i*4 + 3]);
        printdos(print, tm->status.computer);
    }
    for (int i = 4 * rows; i < 4 * rows + rem; i++) {
        snprintf(print, PRINT_BUF, "%-9s ", cmd_protec[i]);
        printdos(print, tm->status.computer);
    }
    printdos("\n-- Protected commands require typing the exact command.\n", tm->status.computer);
}

void cmd_circuits(struct time_machine* tm, struct player* p) {
    printdos("circuits goes moo.\n", tm->status.computer);
}

void cmd_calculate(struct time_machine* tm, struct player* p) {
    printdos("calculate goes moo.\n", tm->status.computer);
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

void cmd_odds(struct time_machine* tm, struct player* p) {
    printdos("Never tell me the odds.\n", tm->status.computer);
}

/***** tdos protected command functions *****/

void cmd_lookaway(struct time_machine* tm, struct player* p) {
    printdos("You look away from the console.\n", tm->status.computer);
    lineprint('_', 64);
    delay(4096);
    p->view = VIEW_INSIDE;
}

void cmd_travel(struct time_machine* tm, struct player* p) {
    printdos("travel goes moo.\n", tm->status.computer);
}

void cmd_exit(struct time_machine* tm, struct player* p) {
    printdos("\nYou look away from the screen and pause the game.\n", tm->status.computer);
    lineprint('_', 64);
    p->paused = true;
    delay(4096);
}

void cmd_emergency(struct time_machine* tm, struct player* p) {
    printdos("emergency goes moo.\n", tm->status.computer);
}

/***** tdos non-command functions *****/

void cmd_error(struct time_machine* tm) {
    snprintf(print, PRINT_BUF, "%s?\n", cmd);
    printdos(print, tm->status.computer);
    delay(1024);
}

void cmd_null(struct time_machine* tm) {
    printdos("null goes moo.\n", tm->status.computer);
}

#ifdef DEBUG
void cmd_debug(struct time_machine* tm, struct player* p) {
    printdos("debug goes moo.\n", tm->status.computer);
}

void cmd_reroll(struct time_machine* tm, struct player* p) {
    printdos("reroll goes moo.\n", tm->status.computer);
}
#endif
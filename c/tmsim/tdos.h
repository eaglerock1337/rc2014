#ifndef TDOS_H_
#define TDOS_H_

#include <stdbool.h>
#include <stdint.h>

#include "tm.h"
#include "player.h"

/***************************************
* TMSim - TDOS system header file
***************************************/

/***** command constants & preprocessor declarations *****/

#define VERSION         "0.0.5"
#define COMPILED        "08/26/2023"

#define CMD_STATUS      0
#define CMD_LOOKAWAY    1
#define CMD_DATE        2
#define CMD_SENSORS     3
#define CMD_HELP        4
#define CMD_CIRCUITS    5
#define CMD_CALCULATE   6
#define CMD_EMERGENCY   7
#define CMD_INVENTORY   8
#define CMD_PLAYER      9
#define CMD_SHIELD      10
#define CMD_MOVE        11
#define CMD_REPORT      12
#define CMD_EXIT        13

#define TOTAL_CMD       (sizeof(cmd_list)/sizeof(cmd_list[0]))

#define CMD_ERROR       98
#define CMD_NULL        99

#ifdef DEBUG
#define CMD_DEBUG       100
#define CMD_REROLL      101
#endif

// primary command list
static char* cmd_list[] = {
    "status",
    "lookaway",
    "date",
    "sensors",
    "help",
    "circuits",
    "calculate",
    "emergency",
    "inventory",
    "player",
    "shield",
    "move",
    "report",
    "exit"
};

// debug commands
#ifdef DEBUG
static char* debug_list[] = {
    "debug",
    "reroll"
};

#define TOTAL_DEBUG     (sizeof(debug_list)/sizeof(debug_list[0]))
#else
#define TOTAL_DEBUG     0
#endif

/***** command string buffer *****/
static char cmd_buffer[32];         // half-size of print buffer
static char* cmd = cmd_buffer;      // TDOS command string buffer
#define CMD_BUF     (sizeof(cmd)/sizeof(char*))

/***** main tdos functions *****/

// the main TDOS command loop
void tdos_command_loop(struct time_machine*, struct player*);

// check TDOS command input and return a status code
uint8_t check_cmd(char*);

// TDOS string array print routine
void printarr(char*[], uint8_t);

// TDOS module print routine
void printdos(char*, uint8_t);

// the TDOS bootstrapper ROM sequence
bool cold_boot(struct time_machine*);

// the TDOS ROM loading sequence
void warm_boot(struct time_machine*);

/***** tdos command functions *****/

// command - status - get overall game status from computer
void cmd_status(struct time_machine*, struct player*);

// command - status - look away from the screen to return to main game loop
void cmd_lookaway(struct time_machine*, struct player*);

// command - date - get information about the current date
void cmd_date(struct time_machine*, struct player*);

// command - sensors - use sensors to detect area resources and threats
void cmd_sensors(struct time_machine*, struct player*);

// command - help - TDOS help command
void cmd_help(struct time_machine*, struct player*);

// command - circuits - time circuit calibration
void cmd_circuits(struct time_machine*, struct player*);

// command - calculate - calculate spacetime trajectories
void cmd_calculate(struct time_machine*, struct player*);

// command - emergency - emergency time travel routine
void cmd_emergency(struct time_machine*, struct player*);
 
// command - inventory - get time machine inventory
void cmd_inventory(struct time_machine*, struct player*);

// command - player - get player status
void cmd_player(struct time_machine*, struct player*);

// command - shield - manage invisibility shield
void cmd_shield(struct time_machine*, struct player*);

// command - move - move the time machine
void cmd_move(struct time_machine*, struct player*);

// command - report - get detailed reports from the computer
void cmd_report(struct time_machine*, struct player*);

// command - exit - exit the simulation
void cmd_exit(struct time_machine*, struct player*);

// command - error - process a command error
void cmd_error(struct time_machine*);

// command - null - process a null command
void cmd_null(struct time_machine*);

#ifdef DEBUG
// command - debug - debug the game using the computer
void cmd_debug(struct time_machine*, struct player*);

// command - reroll - reroll the game using a new difficulty
void cmd_reroll(struct time_machine*, struct player*);
#endif

#endif

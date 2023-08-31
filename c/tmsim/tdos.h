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

#define VERSION         "0.1.0"
#define COMPILED        "08/30/2023"

// normal commands (allows for shortcuts)
#define CMD_STATUS      0
#define CMD_DATE        1
#define CMD_SENSORS     2
#define CMD_HELP        3
#define CMD_CIRCUITS    4
#define CMD_CALCULATE   5
#define CMD_INVENTORY   6
#define CMD_PLAYER      7
#define CMD_SHIELD      8
#define CMD_MOVE        9
#define CMD_REPORT      10
#define CMD_ODDS        11

// protected commands (full command required)
#define CMD_LOOKAWAY    50
#define CMD_TRAVEL      51
#define CMD_EXIT        52
#define CMD_EMERGENCY   53

#define TOTAL_CMD       (sizeof(cmd_list)/sizeof(cmd_list[0]))
#define TOTAL_PROTEC    (sizeof(cmd_protec)/sizeof(cmd_protec[0]))

// non-commands
#define CMD_ERROR       98
#define CMD_NULL        99

// debug commands
#ifdef DEBUG
#define CMD_DEBUG       100
#define CMD_REROLL      101
#endif

// primary command list
static char* cmd_list[] = {
    "status",
    "date",
    "sensors",
    "help",
    "circuits",
    "calculate",
    "inventory",
    "player",
    "shield",
    "move",
    "report",
    "odds"
};

// protected command list
static char* cmd_protec[] = {
    "lookaway",
    "travel",
    "exit",
    "emergency"
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

// TDOS module print routine
void printdos(char*, uint8_t);

// the TDOS bootstrapper ROM sequence
bool cold_boot(struct time_machine*);

// the TDOS ROM loading sequence
void warm_boot(struct time_machine*);

/***** tdos normal command functions *****/

// command - status - get overall game status from computer
void cmd_status(struct time_machine*, struct player*);

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

// command - odds - "Never tell me the odds."
//           get success probabilities for certain tasks
void cmd_odds(struct time_machine*, struct player*);

/***** tdos protected command functions *****/

// command - status - look away from the screen to return to main game loop
void cmd_lookaway(struct time_machine*, struct player*);

// command - travel - main time travel routine
void cmd_travel(struct time_machine*, struct player*);
 
// command - exit - exit the simulation
void cmd_exit(struct time_machine*, struct player*);

// command - emergency - emergency time travel routine
void cmd_emergency(struct time_machine*, struct player*);
 
/***** tdos non-command functions *****/

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

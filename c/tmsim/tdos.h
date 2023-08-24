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

#define CMD_STATUS      0
#define CMD_LOOKAWAY    1
#define CMD_DATE        2
#define CMD_SENSORS     3
#define CMD_HELP        4
#define CMD_CALCULATE   5
#define CMD_EMERGENCY   6
#define CMD_INVENTORY   7
#define CMD_PLAYER      8
#define CMD_SHIELD      9
#define CMD_MOVE        10
#define CMD_REPORT      11
#define CMD_EXIT        12

#define TOTAL_CMD       (sizeof(commands)/sizeof(cmd_list[0]))
#define CMD_ERROR       98
#define CMD_NULL        99

#ifdef DEBUG
#define CMD_REROLL      TOTAL_CMD - 2
#define CMD_DEBUG       TOTAL_CMD - 1
#endif

const static char* cmd_list[] = {
    "status"
    "lookaway",
    "date",
    "sensors",
    "help",
    "calculate",
    "emergency",
    "inventory",
    "player",
    "shield",
    "move",
    "report",
    "exit"
#ifdef DEBUG
    , "reroll"
    , "debug"
#endif
};

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

// the TDOS boot sequence
bool boot(struct time_machine*);

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
// command - reroll - reroll the game using a new difficulty
void cmd_reroll(struct time_machine*, struct player*);

// command - debug - debug the game using the computer
void cmd_debug(struct time_machine*, struct player*);
#endif

#endif

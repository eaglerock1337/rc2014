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

#define NUMCOMMANDS (sizeof(commands)/sizeof(commands[0]))
#define CMD_ERROR       98
#define CMD_NULL        99

#ifdef DEBUG
#define CMD_REROLL      NUMCOMMANDS - 2
#define CMD_DEBUG       NUMCOMMANDS - 1
#endif

const static char* command_list[] = {
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
static char cmd_buffer[32];                // half-size of print buffer
static char* cmd = cmd_buffer;     // TDOS command string buffer
#define CMD_BUF     (sizeof(cmd)/sizeof(char*))

/***** main tdos functions *****/

// the main TDOS command loop
void tdos_command_loop(struct time_machine*, struct player*);

// check TDOS command input and return a status code
int check_cmd(char*);

// TDOS string array print routine
void printarr(char*[], uint8_t);

// TDOS module print routine
void printdos(char*, uint8_t);

// the TDOS boot sequence
bool boot(struct time_machine*);

/***** tdos command functions *****/

#ifdef DEBUG
// the tdos debug command
bool debug_me(struct time_machine*, struct player*);
#endif

#endif

#ifndef SIM_H_
#define SIM_H_

#include <stdint.h>

#include "player.h"
#include "tm.h"

/***************************************
* TMSim - Main simulator header file
***************************************/

// text print speeds
#define FAST    0
#define NORM    1
#define SLOW    2

/***** view constants *****/

#define VIEW_INSIDE     0
#define VIEW_CONTROL    1
#define VIEW_BREAKER    2
#define VIEW_COMPUTER   3
#define VIEW_CONSOLE    4
#define VIEW_STORAGE    5
#define VIEW_OUTSIDE    6

/***** action preprocessor declarations *****/

// view-based actions - ASCII 1-9
#define ACTION ONE      0x31
#define ACTION_TWO      0x32
#define ACTION_THREE    0x33
#define ACTION_FOUR     0x34
#define ACTION_FIVE     0x35
#define ACTION_SIX      0x36
#define ACTION_SEVEN    0x37
#define ACTION_EIGHT    0x38
#define ACTION_NINE     0x39

// general actions - ASCII letters
#define ACTION_HELP     0x48    // uppercase H
#define ACTION_LOOK     0x4C    // uppercase L
#define ACTION_PAUSE    0x50    // uppercase P

/***** primary input buffer *****/

static char input_buffer[32];       // half-size of print buffer
static char* input = input_buffer;  // TDOS command string buffer
#define INPUT_BUF       (sizeof(input)/sizeof(input*))

/***** main simulator functions *****/

// the main simulator control loop
void sim_loop(struct time_machine*, struct player*);

// sim loop wrapper function for entering and exiting simulator
void enter_sim_loop(struct time_machine*, struct player*);

/***** simulator view functions *****/

// view - sitting inside the time machine
void view_inside(struct time_machine*, struct player*);

// view - looking at the control panel
void view_control_panel(struct time_machine*, struct player*);

// view - looking at the breaker panel
void view_breaker_panel(struct time_machine*, struct player*);

// view - looking at the RC2014 computer
void view_computer(struct time_machine*, struct player*);

// view - looking at the time machine console
void view_console(struct time_machine*, struct player*);

// view - looking at the storage compartment
void view_storage(struct time_machine*, struct player*);

// view - outside of the time machine
void view_outside(struct time_machine*, struct player*);

/***** simulator action functions *****/

// action - get some help
void action_help();

// action - pause the game
void action_pause(struct player*);

/***** simulator helper routines *****/

// narrate the game with the tmprint function
void narrate(char*, uint8_t);

// interpret provided response for letter-based actions from the player
void check_general_actions(struct time_machine*, struct player*, int);

#endif
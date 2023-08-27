#ifndef SIM_H_
#define SIM_H_

#include <stdint.h>

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
#define VIEW_OUTSIDE    1
#define VIEW_CONSOLE    2
#define VIEW_CONTROL    3
#define VIEW_BREAKER    4

/***** action constants & preprocessor declarations *****/

#define SIM_EXAMPLE     0
#define SIM_EXAMPLE2    1

/***** main simulator functions *****/

// the main simulator control loop
void sim_loop(struct time_machine*, struct player*);

// sim loop wrapper function for entering and exiting simulator
void enter_sim_loop(struct time_machine*, struct player*);

/***** simulator view functions *****/

// view - sitting inside the time machine
void view_inside(struct time_machine*, struct player*);

// view - outside of the time machine
void view_outside(struct time_machine*, struct player*);

// view - looking at the time machine console
void view_console(struct time_machine*, struct player*);

// view - looking at the control panel
void view_control_panel(struct time_machine*, struct player*);

// view - looking at the breaker panel
void view_breaker_panel(struct time_machine*, struct player*);

/***** simulator action functions *****/

/***** simulator helper routines *****/

// narrate the game with the tmprint function
void narrate(char*, uint8_t);

#endif
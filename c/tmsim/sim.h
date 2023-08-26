#ifndef SIM_H_
#define TM_H_

/***************************************
* TMSim - Main simulator module
***************************************/

/***** action constants & preprocessor declarations *****/

#define SIM_EXAMPLE     0
#define SIM_EXAMPLE2    1

/***** main simulator functions *****/

// the main simulator command loop
void sim_loop(struct time_machine*, struct player*);

/***** simulator action functions *****/

#endif
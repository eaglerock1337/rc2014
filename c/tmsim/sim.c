#include <stdint.h>
#include <stdio.h>

#include "player.h"
#include "sim.h"
#include "tdos.h"
#include "text.h"
#include "tm.h"

/***************************************
* TMSim - Main simulator module
***************************************/

void sim_loop(struct time_machine* tm, struct player* p) {
    while (!p->paused) {
        switch (p->view) {
        case VIEW_INSIDE:   view_inside(tm, p);         break;
        case VIEW_OUTSIDE:  view_outside(tm, p);        break;
        case VIEW_CONSOLE:  view_console(tm, p);        break;
        case VIEW_CONTROL:  view_control_panel(tm, p);  break;
        case VIEW_BREAKER:  view_breaker_panel(tm, p);  break;
        default:    printf("Something went wrong in sim_loop()\n");
        }
    }
}

void enter_sim_loop(struct time_machine* tm, struct player* p) {
    p->paused = false;
    p->new_view = false;
    narrate("You are now entering the simulation.\n", NORM);
    lineprint('=', 64);
    delay(4096);
    sim_loop(tm, p);
    lineprint('=', 64);
    narrate("Simulation paused. Returning to main menu.\n\n", FAST);
}

/***** simulator view functions *****/

void view_inside(struct time_machine* tm, struct player* p) {
    if (p->new_view) {
        narrate("You are sitting inside the time machine. The", SLOW);
    } else {
        narrate("You are still sitting inside the time machine.\n\n", NORM);
    }
}

void view_outside(struct time_machine* tm, struct player* p) {
    // TODO: outside loop goes here
}

void view_console(struct time_machine* tm, struct player* p) {
    narrate("You turn your attention to the console screen.\n", NORM);
    lineprint('-', 64);
    delay(8192);
    tdos_command_loop(tm, p);
    // TODO: time processing goes here
}

void view_control_panel(struct time_machine* tm, struct player* p) {
    // TODO: control panel loop goes here
}

void view_breaker_panel(struct time_machine* tm, struct player* p) {
    // TODO: breaker panel goes here
}

/***** simulator action functions *****/

/***** simulator helper functions *****/

void narrate(char* str, uint8_t speed) {
    switch (speed) {
    case FAST:  tmprint(str, FAST_NARR);    return;
    case NORM:  tmprint(str, NORM_NARR);    return;
    case SLOW:  tmprint(str, SLOW_NARR);    return;
    default: printf("Something went wrong in narrate()\n");
    }
}

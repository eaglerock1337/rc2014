#include <ctype.h>
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
        case VIEW_INSIDE:       view_inside(tm, p);         break;
        case VIEW_CONTROL:      view_control_panel(tm, p);  break;
        case VIEW_BREAKER:      view_breaker_panel(tm, p);  break;
        case VIEW_COMPUTER:     view_computer(tm, p);       break;
        case VIEW_CONSOLE:      view_console(tm, p);        break;
        case VIEW_STORAGE:      view_storage(tm, p);        break;
        case VIEW_OUTSIDE:      view_outside(tm, p);        break;
        default:    printf("Something went wrong in sim_loop()\n");
        }
    }
}

void enter_sim_loop(struct time_machine* tm, struct player* p) {
    p->paused = false;
    p->new_view = true;
    narrate("You are now entering the simulation.\n", NORM);
    lineprint('=', 64);
    delay(4096);
    sim_loop(tm, p);
    narrate("Simulation paused. Returning to main menu.\n", FAST);
    lineprint('=', 64);
    delay(4096);
}

/***** simulator view functions *****/

void view_inside(struct time_machine* tm, struct player* p) {
    if (p->new_view) {
        p->new_view = false;
        narrate("You are sitting inside the time machine.\n"
                "Amidst the mess of wires and exposed circuitry, you can use\n"
                "(1) the main CONTROL panel,    (2) a circuit BREAKER panel,\n", NORM);
        narrate("(3) a small, open COMPUTER and (4) its CONSOLE and keyboard,\n"
                "(5) a STORAGE compartment, and (6) the airlock to OUTSIDE.\n", NORM);
    } else {
        narrate("You are still sitting inside the time machine.\n", NORM);
    }
    delay(2048);
    input[0] = get_response();     // pull one char into the input buffer
    switch(input[0]) {
    case 1:     p->view = VIEW_CONTROL; p->new_view = true;     break;
    case 2:     p->view = VIEW_BREAKER; p->new_view = true;     break;
    case 3:     p->view = VIEW_COMPUTER; p->new_view = true;    break;
    case 4:     p->view = VIEW_CONSOLE; p->new_view = true;     break;
    case 5:     p->view = VIEW_STORAGE; p->new_view = true;     break;
    case 6:     p->view = VIEW_OUTSIDE; p->new_view = true;     break;
    default:    check_general_actions(tm, p, input[0]);
    }
}

void view_control_panel(struct time_machine* tm, struct player* p) {
    // TODO: control panel loop goes here
    narrate("NO CONTROL PANEL FOR YOU! COME BACK ONE YEAR!\n", SLOW);
    p->view = VIEW_INSIDE;
    p->new_view = true;
}

void view_breaker_panel(struct time_machine* tm, struct player* p) {
    // TODO: breaker panel goes here
    narrate("The breaker panel dun broke.\n", SLOW);
    p->view = VIEW_INSIDE;
    p->new_view = true;
}

void view_computer(struct time_machine* tm, struct player* p) {
    // TODO: computer section goes here
    narrate("If there was a computer to look at, that would be nice, right?\n", SLOW);
    p->view = VIEW_INSIDE;
    p->new_view = true;
}

void view_console(struct time_machine* tm, struct player* p) {
    narrate("You turn your attention to the console screen.\n", NORM);
    lineprint('_', 64);
    delay(8192);
    tdos_command_loop(tm, p);
    // TODO: time processing for post-tdos use goes here
}

void view_storage(struct time_machine* tm, struct player* p) {
    // TODO: storage compartment goes here
    narrate("You forgot to pay your storage bill and are locked out.\n", SLOW);
    p->view = VIEW_INSIDE;
    p->new_view = true;
}

void view_outside(struct time_machine* tm, struct player* p) {
    // TODO: outside loop goes here
    narrate("Go outside, touch grass, then come back.\n", SLOW);
    p->view = VIEW_INSIDE;
    p->new_view = true;
}

/***** simulator action functions *****/

void action_help() {
    // TODO: help me.
}

void action_pause(struct player* p) {
    narrate("Pausing the game.\n", NORM);
    p->paused = true;
}

/***** simulator helper functions *****/

void narrate(char* str, uint8_t speed) {
    switch (speed) {
    case FAST:  tmprint(str, FAST_NARR);    return;
    case NORM:  tmprint(str, NORM_NARR);    return;
    case SLOW:  tmprint(str, SLOW_NARR);    return;
    default: printf("Something went wrong in narrate()\n");
    }
}

void check_general_actions(struct time_machine* tm, struct player* p, int response) {
    switch (toupper(response)) {
    case ACTION_HELP:   action_help();          break;
    case ACTION_LOOK:   p->new_view = true;     break;
    case ACTION_PAUSE:  action_pause(p);        break;        
    default: narrate("Input not recognized.\n", NORM);
    }
}

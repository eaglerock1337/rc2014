#include <stdio.h>
#include <stdint.h>

/***************************************
* TMSim - Time machine header file
***************************************/

#define OFF     0   // component off
#define ON      1   // component on
#define FAULT   2   // component fault

#define OPEN    0   // air lock open
#define CLOSED  1   // air lock closed

/***** data structures *****/

struct time_machine_parts {
    uint8_t exterior[6];
    uint8_t interior[6];
    uint8_t computer[6];
};

struct time_machine_status {
    uint8_t exterior[6];
    uint8_t interior[6];
    uint8_t computer;       // single switch
};

struct time_machine {
    struct time_machine_parts parts;
    struct time_machine_status status;
    uint32_t energy;
};

/***** functions *****/

// rolls a single part status based on a 1-5 difficulty
uint8_t roll_part(uint8_t);

// roll time machine part stats based on a 1-5 difficulty
void roll_parts(uint8_t, struct time_machine_parts*);

// get a time machine struct with initialized stats
struct time_machine get_time_machine(uint8_t);

// returns an exterior part name based on its array ID
char* get_exterior_part(uint8_t);

// returns an interior part name based on its array ID
char* get_interior_part(uint8_t);

// returns a computer part name based on its array ID
char* get_computer_part(uint8_t);

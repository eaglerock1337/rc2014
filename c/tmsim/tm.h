#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/***************************************
* TMSim - Time machine header file
***************************************/

#define OFF     0   // component off
#define ON      1   // component on
#define FAULT   2   // component fault

#define OPEN    0   // air lock open
#define CLOSED  1   // air lock closed

// display statuses
#define OK      0   // nominal status
#define INF     1   // info status
#define WRN     2   // warning status
#define FLT     3   // fault status

// exterior part values
#define AIRLOCK 0
#define SHIELD  1
#define HOVER   2
#define TESLA   3
#define FUSION  4
#define STEAM   5

// interior part values
#define RC2014      0
#define POWER       1
#define SUPPORT     2
#define CIRCUITS    3
#define SENSORS     4
#define CONSOLE     5

// exterior power bitwise vales
#define AIRLOCK_ON  1
#define SHIELD_ON   2
#define HOVER_ON    4
#define TESLA_ON    8
#define FUSION_ON   16
#define STEAM_ON    32
#define EXT_READY   64

// interior power bitwise values
#define POWER_ON    1
#define SUPPORT_ON  2
#define CIRCUITS_ON 4
#define SENSORS_ON  8
#define CONSOLE_ON  16
#define COMPUTER_ON 32
#define INT_READY   64

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
    uint32_t energy;        // energy 
    uint8_t tm_status;      // main status
    struct time_machine_status status;
    struct time_machine_parts parts;
    uint8_t ext_power;      // bitwise
    uint8_t int_power;      // bitwise
};

/***** functions *****/

// rolls a single part status based on a 1-5 difficulty
uint8_t roll_part(uint8_t);

// roll time machine part stats based on a 1-5 difficulty
void roll_parts(uint8_t, struct time_machine_parts*);

// get a time machine struct with initialized stats
struct time_machine get_time_machine(uint8_t);

// get bitwise power status of an exterior part by ID
bool get_exterior_power(uint8_t);

// get bitwise power status of an interior part by ID
bool get_interior_power(uint8_t);

// returns an exterior part name based on its array ID
char* get_exterior_part(uint8_t);

// returns an interior part name based on its array ID
char* get_interior_part(uint8_t);

// returns a computer part name based on its array ID
char* get_computer_part(uint8_t);

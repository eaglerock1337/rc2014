#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/***************************************
* TMSim - Time machine header file
***************************************/

// basic on/off values
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

// exterior part power values
#define AIRLOCK     0
#define SHIELD      1
#define HOVER       2
#define TESLA       3
#define FUSION      4
#define STEAM       5
#define EXTERIOR    6

// interior part power values
#define RC2014      0
#define POWER       1
#define SUPPORT     2
#define CIRCUITS    3
#define SENSORS     4
#define CONSOLE     5
#define INTERIOR    6

// exterior power bitwise vales
#define AIRLOCK_ON  1
#define SHIELD_ON   2
#define HOVER_ON    4
#define TESLA_ON    8
#define FUSION_ON   16
#define STEAM_ON    32
#define EXT_READY   64

// interior power bitwise values
#define RC2014_ON   1
#define POWER_ON    2
#define SUPPORT_ON  4
#define CIRCUITS_ON 8
#define SENSORS_ON  16
#define CONSOLE_ON  32
#define INT_READY   64

/***** data structures *****/

struct time_machine_parts {
    uint8_t exterior[6];    // 0-100 for all values
    uint8_t interior[6];
    uint8_t computer[6];
};

// could maybe optimize this later with 2-bit words
struct time_machine_status {
    uint8_t exterior[6];
    uint8_t interior[6];
    uint8_t computer;       // single switch
};

struct time_machine {
    uint32_t energy;        // energy 
    uint8_t tm_status;      // main status
    struct time_machine_parts wear;     // part wear 0-100%
    struct time_machine_parts tear;     // part tear 0-100%
    uint8_t ext_power;      // bitwise
    uint8_t int_power;      // bitwise
    uint8_t computer;       // power status
};

/***** init functions *****/

// rolls a single part status based on a 1-5 difficulty
uint8_t roll_part(uint8_t);

// roll time machine part stats based on a 1-5 difficulty
void roll_parts(uint8_t, struct time_machine_parts*);

// main time machine data structure
struct time_machine get_time_machine(uint8_t);

/***** helper functions *****/

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

// set a bit or bits with the provided mask
void set_bits(uint8_t* byte, uint8_t mask);

// unset a bit or bits with the provided mask
void unset_bits(uint8_t* byte, uint8_t mask);

/****** data functions *****/

// refresh the power status of the time machine
void refresh_power_data(struct time_machine*);

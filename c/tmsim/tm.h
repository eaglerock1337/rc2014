#ifndef TM_H_
#define TM_H_

#include <stdbool.h>
#include <stdint.h>

/***************************************
* TMSim - Time machine header file
***************************************/

// basic on/off values
#define OFF     0   // component off
#define ON      1   // component on

#define OPEN    0   // air lock open
#define CLOSED  1   // air lock closed

// display statuses
#define NOM     0   // nominal status
#define INF     1   // info status
#define WRN     2   // warning status
#define FLT     3   // fault status

// part types
#define EXTERIOR    0
#define INTERIOR    1
#define COMPUTER    2

// exterior part status ids
#define AIRLOCK     0
#define SHIELD      1
#define HOVER       2
#define TESLA       3
#define FUSION      4
#define STEAM       5

#define IS_READY    6
#define PC_CHECK    7

// interior part status ids
#define RC2014      0
#define POWER       1
#define SUPPORT     2
#define CIRCUITS    3
#define SENSORS     4
#define CONSOLE     5

// RC2014 computer part ids
#define BACKPLANE   0
#define CLOCK       1
#define CPU         2
#define MEMORY      3
#define SERIAL_IO   4
#define HW_BRIDGE   5

// exterior power bitwise vales
#define AIRLOCK_ON  1
#define SHIELD_ON   2
#define HOVER_ON    4
#define TESLA_ON    8
#define FUSION_ON   16
#define STEAM_ON    32

#define AIRLOCK_FLT 64
#define SHIELD_FLT  128
#define HOVER_FLT   256
#define TESLA_FLT   512
#define FUSION_FLT  1024
#define STEAM_FLT   2048

// interior power bitwise values
#define RC2014_ON   1
#define POWER_ON    2
#define SUPPORT_ON  4
#define CIRCUITS_ON 8
#define SENSORS_ON  16
#define CONSOLE_ON  32
#define RC2014_FLT  64
#define POWER_FLT   128
#define SUPPORT_FLT 256
#define CIRCUTS_FLT 512
#define SENSORS_FLT 1024
#define CONSOLE_FLT 2048

// general power bitwise values and masks
#define ANY_FAULT   4096    // bit flagging any part faults
#define FLT_MASK    0       // TODO: get proper bit mask for checking for faults
#define FLT_STATE   0       // TODO: get expected state for no faults

#define TT_READY    8192    // bit flagging time travel readiness
#define TT_MASK     0       // TODO: get proper bit mask for checking time travel state
#define TT_STATE    0       // TODO: get expected state for time travel readiness

// TODO: determine if there is any need for the top two bits for system checks

/***** data structures *****/

// a single time machine part's wear & tear values
struct time_machine_part {
    uint8_t wear;       // part's wear value from 0-100%
    uint8_t tear;       // part's tear value from 0-100%
};

// the time machine's complete part wear & tear value set
struct time_machine_parts {
    struct time_machine_part exterior[6];   // exterior part value array
    struct time_machine_part interior[6];   // interior part value array
    struct time_machine_part computer[6];   // computer part value array
};

// the time machine's power status for all parts
struct time_machine_status {
    // could maybe optimize this later with 2 2-bit words
    uint8_t exterior[6];    // 6 exterior part values
    uint8_t interior[6];
    uint8_t computer;       // single switch
};

// the time machine's memory bank
struct time_machine_ram {
    uint8_t aggro;                      // detected aggro
    struct time_machine_parts parts;    // detected part data    
};

struct time_machine {
    uint32_t energy;                    // total energy in kJ
    uint8_t tm_status;                  // main status
    struct time_machine_parts parts;    // wear & tear
    struct time_machine_status status;  // display status
    uint8_t ext_power;                  // bitwise power
    uint8_t int_power;                  // bitwise power
    uint8_t computer;                   // power
};

/***** init functions *****/

// rolls a single part status based on a 1-5 difficulty
uint8_t roll_part(uint8_t);

// roll time machine part stats based on a 1-5 difficulty
void roll_parts(uint8_t, struct time_machine_parts*);

// new game time machine initialization routine
void initialize_tm(uint8_t, struct time_machine*);

/***** bitwise helper functions *****/

// get bitwise power status of an exterior part by ID
bool get_exterior_power(uint8_t, uint8_t);

// get bitwise power status of an interior part by ID
bool get_interior_power(uint8_t, uint8_t);

// set a bit or bits with the provided mask
void set_bits(uint8_t* byte, uint8_t mask);

// unset a bit or bits with the provided mask
void unset_bits(uint8_t* byte, uint8_t mask);

/***** data refresh functions *****/

// refresh the power status of the time machine
void refresh_power_data(struct time_machine*);

// refresh the display status for all time machine parts
void refresh_part_status(struct time_machine*);

/***** data retrieval functions *****/

// get the time machine part based on its id and type
struct time_machine_part* get_part(uint8_t, uint8_t, struct time_machine*);

// return the overall wear/tear condition of the part
uint8_t get_condition(struct time_machine_part*);

// get the part status of a given overall part wear status from 0-100
uint8_t get_part_status(uint8_t);

/***** data manipulation routines *****/

// perform wear and tear on a given part
void wear_part(struct time_machine_part*);

// perform part tear on a given part
void tear_part(struct time_machine_part*);

// turn on a part based on part id and type
void power_part(uint8_t, uint8_t, struct time_machine*);

// attempt to turn on a part & return 1 if successful
bool turn_on_part(uint8_t, uint8_t, struct time_machine*);

// turn off the specified part by id and type
void turn_off_part(uint8_t, uint8_t, struct time_machine*);

/***** print functions *****/

// returns an exterior part name based on its array ID
char* get_exterior_part(uint8_t);

// returns an interior part name based on its array ID
char* get_interior_part(uint8_t);

// returns a computer part name based on its array ID
char* get_computer_part(uint8_t);

// return the status display for the given status id
char* status_disp(uint8_t);

#endif

/* Time Machine TODOs
*   TODO: minimum energy amount for stuff:
*       25kj minimum for base for 1 hour
*       25kj minimum for TDOS for 1 hour
*       1gj for time travel
*   Time travel formula:
*   Energy = Years ^ 2 / 4300 + 1
*       30 years = 1.21gj - because it has to, obviously
*   TODO: time travel routine has a max gj rating check
*/
#ifndef TM_H_
#define TM_H_

#include <stdbool.h>
#include <stdint.h>

/***************************************
* TMSim - Time machine header file
***************************************/

// basic power status
#define OFF     0
#define ON      1

// power string constants
static char* power_str[] = {"OFF", "ON", "FLT"};

// display statuses
#define NOM     0   // nominal status
#define INF     1   // info status
#define WRN     2   // warning status
#define FLT     3   // fault status

// part types
#define AUXILLARY   0
#define CRITICAL    1
#define COMPUTER    2

// critical part status ids
#define POWER       0
#define SUPPORT     1
#define AIRLOCK     2
#define CIRCUITS    3
#define CONSOLE     4
#define RC2014      5
#define ALL_CRIT    6
#define PWR_LOCK    7

// auxillary part status ids
#define SENSORS     0
#define SHIELD      1
#define HOVER       2
#define TESLA       3
#define FUSION      4
#define STEAM       5

// RC2014 computer part ids
#define BACKPLANE   0
#define CLOCK       1
#define Z80_CPU     2
#define MEMORY      3
#define SERIAL_IO   4
#define HW_BRIDGE   5

// critical power bitwise values
#define POWER_ON    1
#define SUPPORT_ON  2
#define AIRLOCK_ON  4
#define CIRCUITS_ON 8
#define CONSOLE_ON  16
#define RC2014_ON   32
#define CRITICAL_ON 64
#define PWR_LOCK_ON 128

// critical status bitwise values
#define POWER_OK    1
#define SUPPORT_OK  2
#define AIRLOCK_OK  4
#define CIRCUITS_OK 8
#define CONSOLE_OK  16
#define RC2014_OK   32
#define CRITICAL_OK 64
#define COORDS_OK   128

// auxillary power bitwise vales
#define SENSORS_ON  1
#define SHIELD_ON   2
#define HOVER_ON    4
#define TESLA_ON    8
#define FUSION_ON   16
#define STEAM_ON    32

// auxillary status bitwise values
#define SENSORS_OK  1
#define SHIELD_OK   2
#define HOVER_OK    4
#define TESLA_OK    8
#define FUSION_OK   16
#define STEAM_OK    32

/***** data structures *****/

// a single time machine part's wear & tear values
struct time_machine_part {
    uint8_t wear;       // part's wear value from 0-100%
    uint8_t tear;       // part's tear value from 0-100%
};

// the time machine's complete part wear & tear value set
struct time_machine_parts {
    struct time_machine_part critical[6];   // core part value array
    struct time_machine_part auxillary[6];  // aux part value array
    struct time_machine_part computer[6];   // rc2014 part value array
};

// the time machine's display status for all parts
struct time_machine_status {
    // TODO: optimize this later with 2 2-bit words
    uint8_t critical[6];    // 6 exterior part values
    uint8_t auxillary[6];
    uint8_t computer;       // single switch
};

// the time machine's memory bank (lost on reset)
struct time_machine_ram {
    uint8_t aggro;                      // detected aggro
    struct time_machine_parts parts;    // detected part data
};

struct time_machine {
    uint32_t energy;                    // total energy in kJ
    struct time_machine_parts parts;    // wear & tear
    struct time_machine_status status;  // display statuses
    uint8_t tm_status;                  // overall system status

    uint8_t crit_power;                 // bitwise power
    uint8_t crit_status;                // bitwise status

    uint8_t aux_power;                  // bitwise power
    uint8_t aux_status;                 // bitwise status
};

/***** init functions *****/

// rolls a single part status based on a 1-5 difficulty
uint8_t roll_part(uint8_t);

// roll time machine part stats based on a 1-5 difficulty
void roll_parts(uint8_t, struct time_machine_parts*);

// new game time machine initialization routine
void initialize_tm(uint8_t, struct time_machine*);

/***** bitwise helper functions *****/

// get bitwise power status of a critical part by ID
bool get_critical_power(uint8_t, uint8_t);

// get bitwise fault status of a critical part by ID
bool get_critical_fault(uint8_t, uint8_t);

// get bitwise power status of an auxillary part by ID
bool get_auxillary_power(uint8_t, uint8_t);

// get bitwise fault status of an auxillary part by ID
bool get_auxillary_fault(uint8_t, uint8_t);

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

// turn on a part on or off based on part id and if critical
void power_part(uint8_t, bool, bool, struct time_machine*);

// fault or reset a part based on part id and if critical
void reset_part(uint8_t, bool, bool, struct time_machine*);

// attempt to turn on a part & return 1 if successful
bool turn_on_part(uint8_t, bool, struct time_machine*);

// turn off the specified part by id and if it is critical
void turn_off_part(uint8_t, bool, struct time_machine*);

/***** print functions *****/

// returns a critical part name based on its array ID
char* get_critical_part(uint8_t);

// returns an auxillary part name based on its array ID
char* get_auxillary_part(uint8_t);

// returns a computer part name based on its array ID
char* get_computer_part(uint8_t);

// returns a printable power status based on ID
char* get_power_status(struct time_machine*, uint8_t, bool);

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
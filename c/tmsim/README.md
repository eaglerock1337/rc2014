# TMSim - A nominally fun time machine simulator

## about

I'll tell you a story all about it later.

## version history

|version|date|about|
|-------|----|-----|
|0.0.0|8/13/23|current attempt start date|
|0.0.1|8/23/23|basic printloop compiling for both x64 and Z80 systems|
|0.0.2|8/24/23|proper string I/O buffers|
|0.0.3|8/25/23|computer command loop & debug mode|
|0.0.4|8/25/23|rethink & rework data structures|
|0.0.5|8/26/23|first commands working|
|0.0.6|8/27/23|main simulation loop started|
|0.0.7|8/28/23|"commands, protected commands."|
|0.0.8|8/29/23|fix compilers & debug text print|
|0.0.9|8/29/23|sim loop input & inside view|
|0.1.0|8/30/23|more sim loop + control view|

## architecture

> This is me trying to divide and conquer, so this might change up.

The project is broken down into multiple modules, the main ones being:

- `tmsim.c`   - game loop for the main menu and its functions
- `sim.c`     - game loop for the simulator and its functions
- `tdos.c`    - game loop for the computer and its functions
- `tm.c`      - struct for time machine state
- `player.c`  - struct for player & simulation state

Additional modules support the game by providing data structures & helper functions:

- `travel.c`  - time travel routines
- `time.c`    - structs for tracking time
- `storage.c` - structs for items & inventory tracking
- `aggro.c`   - outside threats and tracking aggro
- `event.c`   - game events and outcomes
- `intro.c`   - the game introduction & dialogue
- `ending.c`  - the different game endings
- `save.c`    - file load/save routines
- `text.c`    - base-level text print routines

I'm sure I'll have some files containing the game data unless I somehow figure out how to avoid needing to store a lot of game text.

# TMSim - A nominally fun time machine simulator

## about

I'll tell you a story all about it later.

## version history

|version|date|about|
|-------|----|-----|
|0.0.0|8/13/23|current attempt start date|
|0.0.1|8/23/23|basic printloop compiling for both x64 and Z80 systems|
|0.0.2|8/24/23|proper string I/O buffers|

## architecture

> This is me trying to divide and conquer, so this might change up.

The project is broken down into multiple files, the main ones being:

- `tmsim.c`   - the game entrypoint, and main menu loop
- `game.c`    - the main game loop and functions
- `tdos.c`    - game loop & functions while using the computer

Major data structures are handled by these files:

- `tm.c`      - the main time machine struct
- `player.c`  - the player's stats and progress

Additional files support the game by providing data structures & helper functions:

- `travel.c`  - time travel routines
- `aggro.c`   - outside threats and tracking aggro
- `event.c`   - game events and outcomes
- `intro.c`   - the game introduction & dialogue
- `ending.c`  - the different game endings
- `save.c`    - file load/save routines
- `text.c`    - low-level text printing & text file routines for 

I'm sure I'll have some files containing the game data unless I somehow figure out how to avoid needing to store a lot of game text.

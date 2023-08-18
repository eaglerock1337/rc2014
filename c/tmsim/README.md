# TMSim - A nominally fun time machine simulator

## about

I'll tell you a story all about it later.

## architecture

> This is me trying to divide and conquer, so this might change up.

The project is broken down into multiple files, the main ones being:

- `tmsim.c`   - the game entrypoint, main loop, and main menu
- `inside.c`  - game loop & functions inside the time machine
- `tdos.c`    - game loop & functions while using the computer
- `panel.c`   - game loop & functions while using the control panel
- `outside.c` - game loop & functions outside the time machine

Additional files support the game by providing data structures & helper functions:

- `intro.c`   - the game introduction & dialogue
- `player.c`  - the player's stats and progress
- `aggro.c`   - outside threats and tracking aggro
- `tm.c`      - the main time machine struct
- `travel.c`  - time travel routines
- `date.c`    - the current day and local surroundings
- `rc2014.c`  - the time machine computer
- `narrate.c` - game narration & dialogue
- `event.c`   - game events and outcomes
- `ending.c`  - the different game endings
- `save.c`    - file load/save routines

I'm sure I'll have some files containing the game data unless I somehow figure out how to avoid needing to store a lot of game text.

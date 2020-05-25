# Tetris

## ncurses version

I want to design an ncurses version of Tetris to learn more about ncurses
and have more experience programming TUIs.

### Goals/Requirements:

- Have a playing area for the game... to be played in.
- Have all 7 tetris blocks auto generate randomly or in a seemingly random
  order at the top of the playing field.
- Give each of the 7 blocks a different color when it appears.
- Allow the user to use the arrow keys to move the tetris block left or
  right as it falls. Allow the down key to move the tetris block faster.
- Write this in a TDD methodology; write the unit tests before any
  code is written. However, make sure to iterate on the tests. Make sure
  to write integration adn system level tests as well.
- Follow my C standard I am writing.
- Allow the user the ability to rotate the falling tetris block via keys.
- A line of tetris blocks will dissappear once it is completely filled in.
- Decide on a testing framework to use for tests.
- The game will be over once blocks get past the highest spot on the
  playing area.

### Stretch Goals/Requirements:

- Have a holding area for one block when you don't want to use it yet. This will
  accessibly via a keystroke.
- Have a score that shows up for the user on how well they are doing.
  Once a game over has occured, this will be written into a high
  score file that can be viewed.
- Implements 10 different levels that vary in difficulty based on speed (and
  maybe the commonality of different pieces **RESEARCH**
- Design a menu screen for playing the game, quitting, and (if a previous
  strectch goal is met) viewing high scores.

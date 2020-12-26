![image](https://user-images.githubusercontent.com/48676469/100624765-bdd92880-335e-11eb-925a-773091ede695.png)
# cpp-collapse-blocks-game
Console version of a tile matching game inspired by Collapse! (GameHouse) written in C++.

## Description
This game is an improved version of an academic project developed in late 2007 that includes bug fixes, visual enhancements and improved gameplay mechanisms. The game runs on a console and requires user input for interactions. The board can be initialised using default settings, custom settings and files. The user must enter some commands in the console window in order to interact with the game board (mouse is not supported).

## Rules
This puzzle video game, which is inspired by <a target="_blank" title="Collapse!" href="https://en.wikipedia.org/wiki/Collapse!">Collapse!</a> from Gamehouse, involves matching groups of at least 2 blocks (or tiles) with the same colour to remove them from the board. The game ends when only "isolated" blocks are remaining on the board or when all blocks are removed.

## Changes compared to the original academic version
- New additions:
   - Added coloured blocks
   - Added screen clear after each user action during gameplay
   - Added end game screen with stats
   - Added replayability: the application redirects the player to the main menu and does not close anymore when a game ends
   - Added "cancel" command during file name input and "exit" command during game play, to go back to the main menu
- Improvements:
   - Enhanced the visual look of the interfaces
   - Enhanced handling of error messages
   - Enhanced handling of user inputs
   - Enhanced deletion of arrays
- Adjustments:
   - Adjusted player score calculations
   - Adjusted display of row and column index: now starts with 1 instead of 0
   - Increased the maximum size of the game board to 16x16
- Bug fixes:
   - Fixed crash in building game board using invalid file structure
- Code rework:
   - Translated all game texts and source codes from French to English
   - Performed code clean-up and optimisation
   - Added code documentation
   
## Old vs new
Old (2007) | New (2020)
------------ | -------------
![image](https://user-images.githubusercontent.com/48676469/100626860-48228c00-3361-11eb-942a-7cb61432d6bd.png) | ![image](https://user-images.githubusercontent.com/48676469/100626774-304b0800-3361-11eb-9f1e-83d6a4450b6b.png)
![image](https://user-images.githubusercontent.com/48676469/100627338-d860d100-3361-11eb-850e-c1f7fc59f759.png) | ![image](https://user-images.githubusercontent.com/48676469/100627272-c5e69780-3361-11eb-8184-883e5f0f47d9.png)
![image](https://user-images.githubusercontent.com/48676469/100627615-2bd31f00-3362-11eb-91f6-d74aaf4d9385.png) | ![image](https://user-images.githubusercontent.com/48676469/100627674-3db4c200-3362-11eb-81da-8bd8c864c6a8.png)
![image](https://user-images.githubusercontent.com/48676469/100628393-21655500-3363-11eb-94bb-6b395be46bd6.png) | ![image](https://user-images.githubusercontent.com/48676469/100628497-3b9f3300-3363-11eb-98b2-8f5a792a5cb2.png)

## How to play
### Mode 1 - quick game
Type `1` and hit <kbd>Enter</kbd> to start a game with a default board of size 9x9 and 4 colours.
Type the row number and hit <kbd>Enter</kbd>, then type the column number and hit <kbd>Enter</kbd> to remove the selected block. Any adjacent blocks with the same colour will be removed as well.
When the game is over, hit <kbd>Enter</kbd> to return to the main menu.
Type `exit` and hit <kbd>Enter</kbd> anytime at any prompt to end the game and return to the main menu.

### Mode 2 - custom game
Type `2` and hit <kbd>Enter</kbd> to start a game with a board of custom size and custom number of colours.
Type the row number and hit <kbd>Enter</kbd>, repeat with the number of columns and the number colours.
The gameplay is the same as decribed in Mode 1 above...

### Mode 3 - file
Type `3` and hit <kbd>Enter</kbd> then enter the file name to be opened, path can be relative (example: `../../myfile.txt`). File extensions must be included in the path.
The gameplay is the same as decribed in Mode 1 above...

### Mode 4 - quit
Type `4` and hit <kbd>Enter</kbd> to simply quit.

## How to build custom boards using files
One cool feature of the game is that it can open files containing specific data to build customised boards. However a certain data format must be complied with in order for the file to be compatible with the game:
- The first line within the file must be written with three numbers separated by a white space (example: `10 5 4` or `16 16 7`). The three numbers represent the number of rows, the number of columns and the number of colours respectively.
- The following line represents the top most row of the board and must be written with numbers from 1 to 8 separated by a white space. The quantity of numbers on that line  must match the second number entered on the very first line. The numbers 1 to 8 represent colours, with number 8 being an empty space.
- The remaining lines represent the remaining rows of the board going from top to bottom.
- Examples:

The following data | will result in this
------------ | -------------
![image](https://user-images.githubusercontent.com/48676469/100633138-a4d57500-3368-11eb-8ad8-24012275554d.png) | ![image](https://user-images.githubusercontent.com/48676469/100633194-bc146280-3368-11eb-8455-7b528026e882.png)
![image](https://user-images.githubusercontent.com/48676469/100633744-6a200c80-3369-11eb-8edc-9bdfe447739d.png) | ![image](https://user-images.githubusercontent.com/48676469/100633799-7c01af80-3369-11eb-9de3-07511f175bd8.png)

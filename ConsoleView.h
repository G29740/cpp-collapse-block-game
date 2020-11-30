/**
*  ConsoleView.h
*  Purpose: represents the interface between the user and the game board.
*  Features:
*  - Displays the main menu, the game board, info and error messages as well as end game stats on the console
*  - Gets input from user in all interfaces
*  - Checks for invalid user input in all interfaces
*  - Processes the game based on the user input
*  - Handles console text colours
*
*  @author Leye Jin
*  @version 2.0 30-11-2020
*/
#ifndef __VIEW__
#define __VIEW__
#include <string.h>
#include "GameBoard.h"

using namespace std;
class ConsoleView {
   public:
      /**
      *  Constructor of ConsoleView.
      */
      ConsoleView();

      /**
      *  Initialises all ConsoleView attributes.
      */
      void initView();

      /**
      *  Provides the interface to the user, handles game logics and processes inputs.
      */
      void process();

      /**
      *  Displays the main menu interface.
      */
      void displayMainMenu();

      /**
      *  Gets the user input on the main menu and all sub-menus.
      *  Invalid inputs such as wrong menu item or game board attributes are handled with error messages.
      */
      void readMenuInput();

      /**
      *  Displays the game board in a RxC grid (R = number of rows, C = number of columns).
      *  Displays the blocks and their corresponding background colour.
      */
      void displayGameBoard();

      /**
      *  Checks that the game has not ended.
      *  Returns true if game is still going, false if it has ended.
      *
      *  @return true if game is still going, false if it has ended.
      */
      bool checkNotEndGame();

      /**
      *  Return user input in the main menu.
      *
      *  @return menuInput The user input.
      */
      string getMenuInput();

      /**
      *  Return the file name entered by the user.
      *
      *  @return fileName The file name.
      */
      string getFileName();

      /**
      *  Checks if user has entered 'cancel' during file name prompt.
      *
      *  @return true if the user entered 'cancel', false otherwise.
      */
      bool getFileSelectionCanceled();

      /**
      *  Removes the game board from the memory.
      */
      void removeGameBoard();

      /**
      *  Gets user input during game play.
      *  Checks for invalid game board coordinates.
      *  End the game if user enters 'exit' any time during game play.
      */
      void play();

      /**
      *  Displays an error message in the console.
      */
      void displayErrorMessage();

      /**
      *  Displays end game stats such as text, total score and total move count.
      */
      void processEndGame();


      /**
      *  Displays a "thanks for playing" message.
      */
      void displayThanks();

      /**
      *  Sets background and colour for the text that will follow.
      *
      *  Block colour list:
      *  151: BLUE
      *  199: RED
      *  167: GREEN
      *  231: YELLOW
      *  247: WHITE
      *  215: PURPLE
      *  183: CYAN
      *
      *  Text colour list
      *  7: WHITE
      *  4: RED
      *  3: BLUE
      *
      *  @param The console text attribute.
      */
      void txtC(int cl);
   private:
      string menuInput;
      string posInput;
      string fileName;
      int rowInput;
      int columnInput;
      int colourInput;
      int score;
      int moveCount;
      bool notEndGame;
      bool fileSelectionCanceled;
      string errorMessage;
      GameBoard *board;
};
#endif

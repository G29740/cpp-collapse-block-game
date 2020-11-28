/**
*  ConsoleView.h
*  Purpose: represents the interface between the user and the game board
*  Features:
*  - Displays the main menu, the game board, info and error messages as well as end game stats on the console
*  - Gets input from user in all interfaces
*  - Checks for invalid user input in all interfaces
*  - Processes the game based on the user input
*  - Handles console text colours
*
*  @author Leye Jin
*  @version 2.0 27-11-2020
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
      *  @return True if game is still going, false if it has ended.
      */
      bool checkNotEndGame();

      /**
      *  Removes the game board from the memory
      */
      void removeGameBoard();

      void play();
      string getMenuInput();
      string getFileName();
      bool getFileSelectionCanceled();
      void displayErrorMessage();
      void processEndGame();
      void displayThanks();
      void setErrorMessage(string s);

      /**
      *  Sets background and character colour
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

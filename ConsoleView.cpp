/**
   ConsoleView.cpp
   Purpose: represents the interface between the user and the game board

   @author Leye Jin
   @version 2.0 27-11-2020
*/
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include "ConsoleView.h"
#include "GameBoard.h"

using namespace std;

ConsoleView::ConsoleView() {}

void ConsoleView::initView() {
   menuInput = -1;
   rowInput = -1;
   columnInput = -1;
   colourInput = -1;
   notEndGame = true;
   fileSelectionCanceled = false;
   score = 0;
   moveCount = 0;
   errorMessage = "";
   fileName = "";
}

void ConsoleView::process() {
   while (getMenuInput() != "4") {
      initView();
      displayMainMenu();
      readMenuInput();
      if (!getFileSelectionCanceled() && getMenuInput() != "4") {
         while (checkNotEndGame() == true) {
            displayGameBoard();
            displayErrorMessage();
            play();
         }
         displayGameBoard();
         processEndGame();
         removeGameBoard();
      }
      cout << string(100, '\n'); //clear screen, system('cls') is not used as it can cause portability problems
   }
   displayThanks();
}

void ConsoleView::displayMainMenu() {
   cout << "+-----------------------------------------------------+" << endl;
   cout << "|          C++ PROJECT: COLLAPSE BLOCKS GAME          |" << endl;
   cout << "|                                                     |" << endl;
   cout << "|                    ";
   txtC(151);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(199);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(167);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(231);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(247);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(215);
   cout << " ";
   txtC(7);
   cout << " ";
   txtC(183);
   cout << " ";
   txtC(7);
   cout << "                    |" << endl;
   cout << "+-----------------------------------------------------+" << endl;
   cout << "|                     ";
   txtC(3);
   cout << "by G29740";
   txtC(7);
   cout << "                       |" << endl;
   cout << "+-----------------------------------------------------+" << endl;
   cout << "\n\n\n" << endl;
   cout << "Type a number and hit [ENTER]" << endl;
   cout << "[1] to start a game with a default game board" << endl;
   cout << "[2] to start a game with a custom game board" << endl;
   cout << "[3] to start a game from a file" << endl;
   cout << "[4] to quit" << endl;
   cout << "-------------------------------------------------------" << endl;
   cout << "Your input: ";
}

void ConsoleView::readMenuInput() {
   fileSelectionCanceled = false;
   getline(cin, menuInput);
   while ((menuInput != "1") && (menuInput != "2") && (menuInput != "3") && (menuInput != "4")) {
      txtC(4);
      cout << "** (X) Please enter a number from 1 to 4!" << endl;
      txtC(7);
      cout << "Your input: ";
      getline(cin, menuInput);
   }
   if (menuInput == "1") {
      board = new GameBoard();
   }
   if (menuInput == "2") {
      cout << "Number of rows (5-16): ";
      getline(cin, posInput);
      istringstream istr(posInput);
      istr >> rowInput;
      while ((rowInput < 5) || (rowInput > 16)) {
         txtC(4);
         cout << "** (X) Please enter a number from 5 to 16!" << endl;
         txtC(7);
         cout << "Number of rows (5-16): ";
         getline(cin, posInput);
         istr.clear();
         istr.str(posInput);
         istr >> rowInput;
      }
      cout << "Number of columns (5-16): ";
      getline(cin, posInput);
      istr.clear();
      istr.str(posInput);
      istr >> columnInput;
      while ((columnInput < 5) || (columnInput > 16)) {
         txtC(4);
         cout << "** (X) Please enter a number from 5 to 16!" << endl;
         txtC(7);
         cout << "Number of columns (5-16): ";
         getline(cin, posInput);
         istr.clear();
         istr.str(posInput);
         istr >> columnInput;
      }
      cout << "Number of colours (3-7): ";
      getline(cin, posInput);
      istr.clear();
      istr.str(posInput);
      istr >> colourInput;
      while ((colourInput < 3) || (colourInput > 7)) {
         txtC(4);
         cout << "** (X) Please enter a number from 3 to 7!" << endl;
         txtC(7);
         cout << "Number of colours (3-7): ";
         getline(cin, posInput);
         istr.clear();
         istr.str(posInput);
         istr >> colourInput;
      }
      board = new GameBoard(rowInput, columnInput, colourInput);
   }
   if (menuInput == "3") {
      bool fileFound = 0;
      cout << "-------------------------------------------------------" << endl;
      cout << "Enter a file name with the extension (example: test.txt)." << endl;
      cout << "Enter [cancel] to go back to the main menu." << endl << endl;
      cout << "File name: ";
      while ((fileFound == 0) && (fileName != "cancel")) {
         try {
            getline(cin, fileName);
            if (fileName != "cancel") {
               fileName = std::regex_replace(fileName, std::regex("^ +| +$|( ) +"), "$1"); //remove leading and trailing spaces
               board = new GameBoard(fileName);
               fileFound = 1;
            } else {
               fileSelectionCanceled = true;
            }
         } catch (int z) {
            txtC(4);
            switch (z) {
            case 1:
               cout << "** (X) File cannot be found, please try again!" << endl;
               break;
            case 2:
               cout << "** (X) Invalid parameters found in file, please try again!" << endl;
               break;
            case 3:
               cout << "** (X) Too much colours found in file, please try again!" << endl;
               break;
            default:
               cout << "** (X) Malformed file, please try again!" << endl;
            }
            txtC(7);
            cout << "File name: ";
         }
      }
   }

}
void ConsoleView::displayGameBoard() {
   cout << string(100, '\n');
   cout << "\n  +--";
   for (int i = 0; i < board -> getColumns(); i++)
      cout << "---";

   cout << "+" << endl;
   for (int i = 0; i < board -> getRows(); i++) {
      printf("%2i| ", board -> getRows() - i);
      for (int j = 0; j < board -> getColumns(); j++) {
         if (board -> getPosition(i, j) != 8) {
            switch (board -> getPosition(i, j)) {
            case 1:
               txtC(151);
               break;
            case 2:
               txtC(199);
               break;
            case 3:
               txtC(167);
               break;
            case 4:
               txtC(231);
               break;
            case 5:
               txtC(247);
               break;
            case 6:
               txtC(215);
               break;
            default:
               txtC(183);
               break;
            }

            printf("%2i ", board -> getPosition(i, j));
            txtC(7);
         } else
            cout << "   ";
      }
      cout << " |";

      cout << endl;
   }
   cout << "  +";
   for (int i = 0; i < board -> getColumns(); i++)
      cout << "---";
   cout << "--+" << endl;
   cout << "    ";
   for (int i = 0; i < board -> getColumns(); i++)
      printf("%2i ", i + 1);
   cout << endl << endl;
   cout << "Score: " << score;
   cout << "\nBlocks remaining: " << board -> getNbBlocksRemaining();

   cout << endl << endl;
}
bool ConsoleView::checkNotEndGame() {
   return notEndGame;
}
string ConsoleView::getMenuInput() {
   return menuInput;
}
string ConsoleView::getFileName() {
   return fileName;
}

bool ConsoleView::getFileSelectionCanceled() {
   return fileSelectionCanceled;
}
void ConsoleView::removeGameBoard() {
   delete board;
}
void ConsoleView::play() {
   rowInput = -1;
   columnInput = -1;
   cout << "Enter [exit] any time to end the game and return to the main menu." << endl;
   cout << "Enter row number: ";
   getline(cin, posInput);
   if (posInput != "exit") {
      istringstream istr(posInput);
      istr >> rowInput;
      while (((rowInput < 1) || (rowInput > board -> getRows())) && posInput != "exit") {
         txtC(4);
         cout << "** (X) Invalid row number, try again!" << endl;
         txtC(7);
         cout << "Enter row number: ";
         getline(cin, posInput);
         istringstream istr(posInput);
         istr >> rowInput;
      }
      if (posInput != "exit") {
         cout << "Enter column number: ";
         getline(cin, posInput);
         istringstream istr2(posInput);
         istr2 >> columnInput;
         while (((columnInput < 1) || (columnInput > board -> getColumns())) && posInput != "exit") {
            txtC(4);
            cout << "** (X) Invalid column number, try again!" << endl;
            txtC(7);
            cout << "Enter column number: ";
            getline(cin, posInput);
            istringstream istr2(posInput);
            istr2 >> columnInput;
         }
         if (posInput != "exit") {
            if (board -> isValueAround(board -> getRows() - rowInput, columnInput - 1) == 1) {
               board -> removeColours(board -> getRows() - rowInput, columnInput - 1);
               board -> fallColours();
               board -> moveColoursToLeft();
               score += pow(board -> getNbBlocksRemoved(), 2);
               notEndGame = (board -> getRemainingGroups() > 0);
               board -> resetNbBlocksRemoved();
               moveCount++;
               setErrorMessage("");
            } else {
               txtC(4);
               setErrorMessage("\n** (X) Cannot perform action: colour group too small or cell is empty!");
               txtC(7);
            }
            rowInput = -1;
            columnInput = -1;
            colourInput = -1;
         } else
            notEndGame = false;
      } else
         notEndGame = false;
   } else
      notEndGame = false;
}

void ConsoleView::displayErrorMessage() {
   txtC(4);
   cout << errorMessage << endl << endl;
   txtC(7);
}

void ConsoleView::processEndGame() {
   cout << "\n+----------------------------------------------+" << endl;
   cout << "|                End game stats                |" << endl;
   cout << "+----------------------------------------------+" << endl;
   cout << endl;
   cout << ">> Remaining blocks: " << board -> getNbBlocksRemaining() << endl;
   cout << ">> Total move count: " << moveCount << endl;
   if (board -> getNbBlocksRemaining() == 0) {
      cout << ">> Score: " << score << " points" << endl;
      score += (10 * (board -> getColumns() + board -> getRows()));
      txtC(2);
      cout << "+ Bonus all block removed: " << 10 * (board -> getColumns() + board -> getRows()) << endl;
      txtC(7);
   }
   cout << ">> Total score: " << score << " points" << endl;
   cout << "Press [ENTER] to return to the main menu" << endl;
   getline(cin, errorMessage);
}

void ConsoleView::displayThanks() {
   cout << string(100, '\n');
   cout << "\n+-----------------------+" << endl;
   cout << "|  Thanks for playing!  |" << endl;
   cout << "+-----------------------+" << endl;
   cout << string(10, '\n');
}

void ConsoleView::setErrorMessage(string s) {
   errorMessage = s;
}

void ConsoleView::txtC(int cl) {
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cl);
}

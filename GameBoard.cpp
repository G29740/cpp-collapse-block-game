/**
   GameBoard.h
   Purpose: represents the collapse block game board.

   @author Leye Jin
   @version 2.0 30-11-2020
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "GameBoard.h"

GameBoard::GameBoard(void) {
   initBoard(9, 9, 4);
}

GameBoard::GameBoard(int rows, int columns, int colours) {
   initBoard(rows, columns, colours);
}

GameBoard::GameBoard(string fName) {
   int val;
   string fRows;
   nbBlocksRemoved = 0;
   nbBlocksRemaining = 0;
   ifstream f(fName);
   if (!f)
      throw 1;
   else {
      getline(f, fRows);
      istringstream iss(fRows);
      iss >> rows >> columns >> colours;
      if (((rows > 4) && (rows < 17)) && ((columns > 4) && (columns < 17)) &&
         ((colours > 2) && (colours < 8))) {
         gameBoard = new int * [this -> rows];

         for (int i = 0; i < this -> rows; i++)
            this -> gameBoard[i] = new int[this -> columns];
         for (int i = 0; i < this -> rows; i++) {
            getline(f, fRows);
            istringstream iss(fRows);
            for (int j = 0; j < this -> columns; j++) {
               iss >> val;
               if (val == 0)
                  throw 4;
               if (((val < 0) || (val > colours)) && (val != 8))
                  throw 3;
               else {
                  if (val != 8)
                     nbBlocksRemaining++;
                  gameBoard[i][j] = val;
               }
            }
            iss.clear();
         }
      } else
         throw 2;
      f.close();
   }
}

GameBoard::~GameBoard(void) {
   for (int i = 0; i < this -> rows; i++)
      delete[] this -> gameBoard[i];
   delete[] gameBoard;
}

void GameBoard::initBoard(int rows, int columns, int colours) {
   nbBlocksRemoved = 0;
   this -> rows = rows;
   this -> columns = columns;
   this -> colours = colours;
   nbBlocksRemaining = rows * columns;
   gameBoard = new int * [this -> rows];
   for (int i = 0; i < this -> rows; i++)
      this -> gameBoard[i] = new int[this -> columns];
   srand(time(0));
   for (int i = 0; i < this -> rows; i++)
      for (int j = 0; j < this -> columns; j++)
         gameBoard[i][j] = (rand() % colours) + 1;
}

int GameBoard::getRows() {
   return this -> rows;
}

int GameBoard::getColumns() {
   return this -> columns;
}

int GameBoard::getColours() {
   return this -> colours;
}

int GameBoard::getPosition(int rowNumber, int columnNumber) {
   return gameBoard[rowNumber][columnNumber];
}

void GameBoard::removeColours(int rowNumber, int columnNumber) {
   int val = gameBoard[rowNumber][columnNumber];
   gameBoard[rowNumber][columnNumber] = 8;

   nbBlocksRemoved++;
   nbBlocksRemaining--;

   if (rowNumber < rows - 1) {
      if (gameBoard[rowNumber + 1][columnNumber] == val)
         removeColours(rowNumber + 1, columnNumber);
   }
   if (rowNumber > 0) {
      if (gameBoard[rowNumber - 1][columnNumber] == val)
         removeColours(rowNumber - 1, columnNumber);
   }
   if (columnNumber < columns - 1) {
      if (gameBoard[rowNumber][columnNumber + 1] == val)
         removeColours(rowNumber, columnNumber + 1);
   }
   if (columnNumber > 0) {
      if (gameBoard[rowNumber][columnNumber - 1] == val)
         removeColours(rowNumber, columnNumber - 1);
   }
}

void GameBoard::fallColours() {
   for (int k = 0; k < rows; k++) {
      for (int i = 1; i < rows; i++) {
         for (int j = 0; j < columns; j++) {
            if (gameBoard[i][j] == 8) {
               gameBoard[i][j] = gameBoard[i - 1][j];
               gameBoard[i - 1][j] = 8;
            }
         }
      }
   }
}

bool GameBoard::isColEmpty(int columnNumber) {
   bool isEmpty = (gameBoard[rows - 1][columnNumber] == 8);
   return isEmpty;
}

void GameBoard::moveColoursToLeft() {
   for (int s = 0; s <= columns / 2; s++) {
      for (int l = 0; l < columns - 1; l++) {
         if (isColEmpty(l)) {
            for (int j = l; j < columns - 1; j++) {
               for (int i = 0; i < rows; i++) {
                  gameBoard[i][j] = gameBoard[i][j + 1];
                  gameBoard[i][j + 1] = 8;
               }
            }
         }
      }
   }
}

bool GameBoard::isValueAround(int rowNumber, int columnNumber) {
   int val = gameBoard[rowNumber][columnNumber];
   bool b = false;
   if (val != 8) {
      b = (((rowNumber < rows - 1 && gameBoard[rowNumber + 1][columnNumber] == val) ||
         (columnNumber < columns - 1 && gameBoard[rowNumber][columnNumber + 1] == val) ||
         (rowNumber > 0 && gameBoard[rowNumber - 1][columnNumber] == val) ||
         (columnNumber > 0 && gameBoard[rowNumber][columnNumber - 1] == val)) && (val != 8));
   }
   return b;
}

bool GameBoard::getRemainingGroups() {
   bool b = 0;
   int i = 0;
   int j = 0;
   if (gameBoard[rows - 1][0] == 8)
      b = 0;
   else {
      while ((i < rows) && (b == 0)) {
         while ((j < columns) && (b == 0)) {
            if (gameBoard[i][j] != 8) {
               b = isValueAround(i, j);
            }
            j++;
         }
         j = 0;
         i++;
      }
   }
   return b;
}

int GameBoard::getNbBlocksRemoved() {
   return nbBlocksRemoved;
}

void GameBoard::resetNbBlocksRemoved() {
   nbBlocksRemoved = 0;
}

int GameBoard::getNbBlocksRemaining() {
   return nbBlocksRemaining;
}

/**
   GameBoard.h
   Purpose: represents the collapse block game board

   @author Leye Jin
   @version 2.0 27-11-2020
*/
#ifndef __GAMEBOARD__
#define __GAMEBOARD__

using namespace std;
class GameBoard {
   public:
      GameBoard();
      GameBoard(int rows, int columns, int colours);
      GameBoard(string fName);
      ~GameBoard(void);
      void initBoard(int rows, int columns, int colours);
      int getRows();
      int getColumns();
      int getPosition(int rowNumber, int columnNumber);
      int getColours();
      void removeColours(int rowNumber, int columnNumber);
      void fallColours();
      bool isColEmpty(int columnNumber);
      void moveColoursToLeft();
      bool isValueAround(int rowNumber, int columnNumber);
      int getNbBlocksRemoved();
      void resetNbBlocksRemoved();
      bool getRemainingGroups();
      int getNbBlocksRemaining();
   private:
      int rows;
      int columns;
      int colours;
      int ** gameBoard;
      int nbBlocksRemoved;
      int nbBlocksRemaining;
};
#endif

/**
   GameBoard.h
   Purpose: represents the collapse block game board.
   Characteristics:
   - The board is defined with minimum 5 and maximum 16 rows X columns
   - Each block (or tile) has a value from 1 to 7 representing 7 different colours, the colour 8 represents an empty cell
   - All logics are handled by this class during game play such as block matching, block falling, etc

   @author Leye Jin
   @version 2.0 30-11-2020
*/
#ifndef __GAMEBOARD__
#define __GAMEBOARD__

using namespace std;
class GameBoard {
   public:
      /**
      * Constructor of GameBoard (default).
      * Defines a board with size of 9x9 and 4 colours.
      */
      GameBoard();

      /**
      * Constructor of GameBoard (with number of rows, columns and colours as parameters).
      * Defines a custom sized and coloured game board.
      *
      * @param rows: number of rows to build, columns: number of columns, colours: number of colours.
      */
      GameBoard(int rows, int columns, int colours);

      /**
      * Constructor of GameBoard (with file name as parameter).
      * Defines a game board based on the values contained in the file.
      * Checks for the structure of the file and throws exceptions when it is invalid.
      *
      * @param fName The file name.
      */
      GameBoard(string fName);

      /**
      * Destructor of GameBoard.
      */
      ~GameBoard(void);

      /**
      * Initialises the board and applies random colours to the blocks using the given parameters.
      * Initialises counters such as score, total number of blocks and move count.
      *
      * @param rows: number of rows to build, columns: number of columns, colours: number of colours.
      */
      void initBoard(int rows, int columns, int colours);

      /**
      * Returns the total number of rows.
      *
      * @return rows The total number of rows.
      */
      int getRows();

      /**
      * Returns the total number of columns.
      *
      * @return columns The total number of columns.
      */
      int getColumns();

      /**
      * Returns the total number of colours.
      *
      * @return colours The total number of colours.
      */
      int getColours();

      /**
      * Returns the block colour at the given position on the board.
      *
      * @return colours The block colour.
      */
      int getPosition(int rowNumber, int columnNumber);

      /**
      * Removes all colour matching blocks (vertically and horizontally) starting from a given position.
      * Updates all counters.
      */
      void removeColours(int rowNumber, int columnNumber);

      /**
      * Fills empty spaces on the board by dropping all "floating" blocks.
      */
      void fallColours();

      /**
      * Checks if there is an empty column on the board.
      *
      * @return true if the column is empty, false otherwise.
      */
      bool isColEmpty(int columnNumber);

      /**
      * Fills empty columns on the board by moving all other columns.
      */
      void moveColoursToLeft();

      /**
      * Checks if the adjacent (V and H only) block colour matches the block at a given position excluding empty cells.
      *
      * @return true if the colour matches, false otherwise.
      */
      bool isValueAround(int rowNumber, int columnNumber);

      /**
      * Return the total number of blocks removed since the start of a game.
      *
      * @return nbBlocksRemoved The total-blocks-removed counter.
      */
      int getNbBlocksRemoved();

      /**
      * Resets the total number of blocks removed (to 0).
      */
      void resetNbBlocksRemoved();

      /**
      * Checks if there is any remaining group of more than 2 colours on the board.
      *
      * @return true if there is a group, false otherwise.
      */
      bool getRemainingGroups();

      /**
      * Returns the number of blocks currently on the board.
      *
      * @return nbBlocksRemaining The number of blocks currently on the board
      */
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

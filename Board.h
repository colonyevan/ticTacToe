#pragma once

#include <ostream>

enum PieceType {
    Empty, Player1, Player2
};

enum Result {
    IllegalMove, Win, Draw, NoResult
};

const int NUM_ROWS = 3,
          NUM_COLS = 3;

const int NUM_FOR_WIN = 3;

const char PLAYER1_TOKEN = 'X',
           PLAYER2_TOKEN = 'O',
           EMPTY_TOKEN = ' ';

class Board {
public:

    /*
     * REquires: Nothing
     * Modifies: *this
     * Effects: Constructs the board with no pieces played
     */
    Board();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the number of the player whose turn it is
     */
    int toMove() const;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Prints the formated board to stream
     */
    void printBoard(std::ostream & stream);

    /*
     * Requires: 0 <= rowChoice < 3
     *           0 <= colChoice < 3
     * Modifies: *this
     *           Changes the position array
     * Effects:  Makes the player move if legal and updates the player turn
     *           If illegal move does NOT update palyer turn and returns IllegalMove
     */
    Result makeMove(int rowChoice, int colChoice);

    /*
     * Requires: Nothing
     * Modifies: *this
     * Effects:  changes the statrting player
     */
    void changeStartingPlayer();

    /*
     * Requires: Nothing
     * Modifies: *this
     * Effects:  Returns the player that is currently up then changes the 
     *           playerUp to the next to move
     */
    PieceType updateToMove();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Checks if the provided pair of ints are in bounds of the 3 x 3 board
     */
    bool inBounds(int row, int col) const;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns true if the board is full
     */
    bool isBoardFull() const;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the number of pieces in a specefic direction
     *           where dRow and dCol represent the delta of each respectivly
     */
    int piecesInDirection(int row, int col, int dRow, int dCol) const;

    /*
     * Requires: 0 <= row < 3
     *           0 <= col < 3
     * Modifies: nothing
     * Effects: Returns true if the piece at that location created a win
     */
    bool isWin(int row, int col) const;

    // Holds the player that is currently to play
    PieceType playerUp;

    // Holds the board
    PieceType position[NUM_ROWS][NUM_COLS];

    // Holds how many turns their have been
    int numTurns;
};


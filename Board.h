#pragma once

#include <exception>
#include <ostream>

enum PieceType {
    Empty,
    Player1,
    Player2
};

enum Result {
    IllegalMove,
    Win,
    Draw,
    NoResult
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
     * Requires: Nothing
     * Modifies: *this
     * Effects: Constructs the board with no pieces played and sets numTurns to 0
     */
    Board();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Prints the formated board to stream
     */
    void printBoard(std::ostream &stream);

    /*
     * Requires: Nothing
     * Modifies: *this
     *           Changes the position array
     * Effects:  Places mover at [rowChoice][colChoice]
     *           Returns outcome of the move
     */
    Result makeMove(int rowChoice, int colChoice, PieceType mover);

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

private:
    // Holds the board
    PieceType position[NUM_ROWS][NUM_COLS];
};
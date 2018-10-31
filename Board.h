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
    Board();

    int toMove() const;

    void printBoard(std::ostream & stream);

    Result makeMove(int rowChoice, int colChoice);

    void changeStartingPlayer();

    PieceType updateToMove();

    bool inBounds(int row, int col) const;

    bool isBoardFull() const;

    int piecesInDirection(int row, int col, int dRow, int dCol) const;

    bool isWin(int row, int col) const;

    PieceType playerUp;

    PieceType position[NUM_ROWS][NUM_COLS];

    int numTurns;
};


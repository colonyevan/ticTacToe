#include "Board.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            position[i][j] = Empty;
        }
    }
    playerUp = Player1;
    numTurns = 0;
}

int Board::toMove() const {
    if (playerUp == Player1) {
        return 1;
    }
    return 2;
}

void Board::printBoard(std::ostream & stream) {
    int count = 0;

    for (int i = 0; i < NUM_ROWS; i++) {
        stream << "      ";
        for (int j = 0; j < NUM_COLS; j++) {
            // Outputs Token
            if (position[i][j] == Player1) {
                stream << PLAYER1_TOKEN;
            } else if (position[i][j] == Player2) {
                stream << PLAYER2_TOKEN;
            } else {
                stream << count + 1;
            }
            if (j == 0 || j == 1) {
                stream << " | ";
            }
            count++;
        }
        if (i == 0 || i == 1) {
            stream << endl << "     ---+---+---" << endl;
        }
    }
    stream << endl;
}

Result Board::makeMove(int rowChoice, int colChoice) {
    if (position[rowChoice][colChoice] != Empty) {
        return IllegalMove;
    }

    position[rowChoice][colChoice] = updateToMove();

    if (isWin(rowChoice, colChoice)) {
        return Win;
    } else if (isBoardFull()) {
        return Draw;
    }
    numTurns++;
    return NoResult;
}

void Board::changeStartingPlayer() {
    if (playerUp == Player1) {
        playerUp = Player2;
    } else {
        playerUp = Player1;
    }
}

PieceType Board::updateToMove() {
    if (playerUp == Player1) {
        playerUp = Player2;
        return Player1;
    }
    playerUp = Player1;
    return Player2;
}

bool Board::inBounds(int row, int col) const {
    if (row > 3 || col > 3 || col < 0 || row < 0) {
        return false;
    }
    return true;
}

bool Board::isBoardFull() const {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (position[i][j] == Empty) {
                return false;
            }
        }
    }
    return true;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    int count = -1;
    PieceType checkingFor = position[row][col];

    while (inBounds(row, col) && position[row][col] == checkingFor) {
        count++;
        row += (1 * dRow);
        col += (1 * dCol);
    }
    return count;
}

bool Board::isWin(int row, int col) const {
    if ((piecesInDirection(row, col, 0, 1) +
        piecesInDirection(row, col, 0, -1)) >= NUM_FOR_WIN - 1) {
        return true;
    }
    else if ((piecesInDirection(row, col, 1, 0) +
        piecesInDirection(row, col, -1, 0)) >= NUM_FOR_WIN - 1) {
        return true;
    }
    else if ((piecesInDirection(row, col, 1, 1) +
        piecesInDirection(row, col, -1, -1)) >= NUM_FOR_WIN - 1) {
        return true;
    }
    else if ((piecesInDirection(row, col, -1, 1) +
        piecesInDirection(row, col, 1, -1)) >= NUM_FOR_WIN - 1) {
        return true;
    }
    return false;
}
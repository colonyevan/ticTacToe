#include "Board.h"

using namespace std;

Board::Board() {
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            position[i][j] = Empty;
        }
    }
}
Board::Board(const Board &inputBoard) {
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            position[row][col] = inputBoard.position[row][col];
        }
    }
}

Board::Board(string input) : Board() {
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == 'X') {
            position[i / 3][i % 3] = Player1;
        } else if (input[i] == 'O') {
            position[i / 3][i % 3] = Player2;
        }
    }
}

void Board::printBoard(std::ostream &stream) {
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
            stream << endl
                   << "     ---+---+---" << endl;
        }
    }
    stream << endl;
}

Result Board::makeMove(int rowChoice, int colChoice, PieceType mover) {
    if (!inBounds(rowChoice, colChoice) ||
        position[rowChoice][colChoice] != Empty) {
        return IllegalMove;
    }

    position[rowChoice][colChoice] = mover;

    if (isWin(rowChoice, colChoice)) {
        return Win;
    } else if (isBoardFull()) {
        return Draw;
    }
    return NoResult;
}

bool Board::inBounds(int row, int col) const {
    if (row > 2 || col > 2 || col < 0 || row < 0) {
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
    } else if ((piecesInDirection(row, col, 1, 0) +
                piecesInDirection(row, col, -1, 0)) >= NUM_FOR_WIN - 1) {
        return true;
    } else if ((piecesInDirection(row, col, 1, 1) +
                piecesInDirection(row, col, -1, -1)) >= NUM_FOR_WIN - 1) {
        return true;
    } else if ((piecesInDirection(row, col, -1, 1) +
                piecesInDirection(row, col, 1, -1)) >= NUM_FOR_WIN - 1) {
        return true;
    }
    return false;
}

vector<int> Board::getOpenSpaces() {
    vector<int> spaces;
    for (int i = 0; i < 9; ++i) {
        if (position[i / 3][i % 3] == Empty) {
            spaces.push_back(i + 1);
        }
    }
    return spaces;
}
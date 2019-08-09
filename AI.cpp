#include "AI.h"
#include <algorithm> // std::max and std::min
#include <iostream>  // std::cout

using namespace std;

AI::~AI() {
}

int simpleAI::getMove(Board *gameBoard, PieceType token) {
    vector<int> openSpaces = gameBoard->getOpenSpaces();
    int choice = openSpaces[rand() % openSpaces.size()];
    cout << "The AI chose " << choice << endl;
    return choice;
}

int mediumAI::getMove(Board *gameBoard, PieceType token) {
    vector<int> openSpaces = gameBoard->getOpenSpaces();
    Result temp = NoResult;
    int move;

    for (size_t i = 0; i < openSpaces.size() && (temp != Win && temp != Draw); ++i) {
        move = openSpaces[i];
        Board tempBoard = *gameBoard;
        temp = tempBoard.makeMove(move / 3, move % 3, token);
    }

    if (temp == IllegalMove) {
        vector<int> openSpaces = gameBoard->getOpenSpaces();
        int choice = openSpaces[rand() % openSpaces.size()];
        cout << "The AI chose " << choice << endl;
        return choice;
    }

    cout << "The AI chose " << move << endl;

    return move;
}

int hardAI::getMove(Board *gameBoard, PieceType token) {
    vector<int> spaces = gameBoard->getOpenSpaces();
    int currentMove = 0;
    int currentScore = 0;

    for (auto i : spaces) {
        int tempVal = minimax(*gameBoard, true, token);
        if (tempVal >= currentScore) {
            currentMove = i;
            currentScore = tempVal;
        }
    }

    cout << "The AI choose " << currentMove << endl;

    return currentMove;
}

int hardAI::minimax(Board gameBoard, bool maxer, PieceType token) {
    vector<int> spaces = gameBoard.getOpenSpaces();

    if (spaces.size() == 1) {
        Board temp = gameBoard;
        Result result = temp.makeMove((spaces[0] - 1) / 3, (spaces[0] - 1) % 3, Player1);
        if (result == Draw) {
            return 0;
        }
        return ((result == Win && token == Player1) ? 1 : -1);
    } else if (maxer) {
        int value = -100;
        for (auto i : spaces) {
            Board temp = gameBoard;
            Result res = temp.makeMove((i - 1) / 3, (i - 1) % 3, ((spaces.size() % 2) == 0 ? Player2 : Player1));
            if (res == Win) {
                return -1;
            }
            value = max(value, minimax(temp, false, token));
        }
        return value;
    } else {
        int value = 100;
        for (auto i : spaces) {
            Board temp = gameBoard;
            Result res = temp.makeMove((i - 1) / 3, (i - 1) % 3, ((spaces.size() % 2) == 0 ? Player2 : Player1));
            if (res == Win) {
                return 1;
            }
            value = min(value, minimax(temp, true, token));
        }
        return value;
    }
}

AI *AIFactory(int level) {
    if (level == 1) {
        return new simpleAI;
    } else if (level == 2) {
        return new mediumAI;
    } else {
        return new hardAI;
    }
}
#include "AI.h"
#include <cassert>
#include <iostream>

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
    vector<int> openSpaces = gameBoard->getOpenSpaces();
    assert(openSpaces.size() != 0);
    int choice = openSpaces[rand() % openSpaces.size()];
    cout << "The AI chose " << choice << endl;
    return choice;
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
#include "AI.h"
#include <iostream>
#include <cassert>

using namespace std;

AI::~AI() {
}

int simpleAI::getMove(Board *gameBoard) {
    vector<int> openSpaces = gameBoard->getOpenSpaces();
    assert(openSpaces.size() != 0);
    int choice = openSpaces[rand() % openSpaces.size()];
    cout << "The AI chose " << choice << endl;
    return choice;
}
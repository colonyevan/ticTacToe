#include "AI.h"

using namespace std;

AI::~AI() {
}

int simpleAI::getMove(Board *gameBoard) {
    vector<int> openSpaces = gameBoard->getOpenSpaces();
    return openSpaces[rand() % openSpaces.size()];
}
#include "Game.h"

using namespace std;

Game::Game() : numTurns(0), gameBoard(Board()){

}

AIGame::AIGame(bool isAI, bool assign = false, int assignTo = 0) : Game() {
    if (isAI) {
        if (assign) {
            numAI = assignTo;
        } else {
            numAI = rand() % 2 + 1;
        }
    }
}


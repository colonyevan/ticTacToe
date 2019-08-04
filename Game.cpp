#include "Game.h"

using namespace std;

Game::Game() : gameBoard(Board()), numTurns(0), p1Name("Alice"), p2Name("Bob") {
}

int Game::getNumTurns() const {
    return numTurns;
}

int Game::getPlayerTurn() const {
    return getNumTurns() % 2 + 1;
}

Result Game::makeMove() {
    gameBoard.printBoard(cout);
    choice temp = getPlay();

    Result result = gameBoard.makeMove(temp.rowChoice, temp.colChoice, getPlayerTurn() == 1 ? Player1 : Player2);
    if (result != IllegalMove) {
        ++numTurns;
    } else {
        cout << "That was an illegal move, try again! " << endl;
    }
    return result;
}

choice Game::getPlay() {
    string name = getPlayerTurn() == 1 ? p1Name : p2Name;
    int place;

    cout << name << ", please enter your move: " << flush;
    cin >> place;

    place -= 1;

    return {place / 3, place % 3};
}

void Game::playGame() {
    Result condition = NoResult;

    while (condition == NoResult || condition == IllegalMove) {
        condition = makeMove();
    }

    if (condition == Draw) {
        cout << "There was a draw, no one won! " << endl;
        return;
    } else {
        cout << (getPlayerTurn() == 1 ? p2Name : p1Name) << ", you won. Congratulations! ";
    }
}

string Game::getPlayerName(int player) {
    return (player == 1 ? p1Name : p2Name);
}

AIGame::AIGame(bool isAI, bool assign, int assignTo) : Game() {
    if (isAI) {
        if (assign) {
            numAI = assignTo;
        } else {
            numAI = rand() % 2 + 1;
        }
    }
}

choice AIGame::getPlay() {
    bool isAITurn = getPlayerTurn() == numAI;
    int place;

    if (isAITurn) {
        place = theAI->getMove();

    } else {
        cout << getPlayerName(getPlayerTurn()) << ", please enter your move: ";
        cin >> place;
    }

    place -=1;

    return {place / 3, place % 3};
}

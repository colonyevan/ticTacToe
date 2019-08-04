#include "AI.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {
    srand(time(NULL));
    //int choice;
    Game *theGame;
    cout << " Would you like to play 1 or 2 player Tic-Tac-Toe (1/2): ";
    // cin >> choice;

    //if (choice == 1) {
        theGame = new AIGame(true);
        cout << "Starting a game against the AI. " << endl;
    //} else {
    //    theGame = new Game;
    //    cout << "Starting a two person game. " << endl;
    //}

    theGame->playGame();
    return 0;
}
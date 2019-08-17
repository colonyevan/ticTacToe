#include "AI.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {
    srand(time(NULL));
    int choice, level;
    Game *theGame;
    cout << "Would you like to play 1 or 2 player Tic-Tac-Toe (1/2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "What level of AI would you like to play against? ";
        cin >> level;
        theGame = new AIGame(true, level);
        cout << "Starting a game against the AI. " << endl;
    } else {
        theGame = new Game;
        cout << "Starting a two person game. " << endl;
    }

    theGame->playGame();
    return 0;
}
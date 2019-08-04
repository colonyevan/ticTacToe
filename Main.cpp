#include "AI.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {
    srand(time(NULL));
    Game theGame;
    theGame.playGame();
    return 0;
}
#pragma once

#include "Board.h"

class AI {
public:
    /*
     * Requies: Nothing
     * Modifies: Nothing
     * Effects:  Returns a move depending on how hard of an AI to paly against
     */
    virtual int getMove(Board *gameBoard) = 0;

    virtual ~AI();
};

class simpleAI : public AI {
    int getMove(Board *gameBoard);
};

class mediumAI : public AI {
    int getMove(Board *gameBoard);
};
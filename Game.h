#pragma once

// Local includes
#include "AI.h"
#include "Board.h"

// Libraries
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

struct choice {
    int rowChoice;
    int colChoice;
};

class Game {
public:
    /*
     * Requires: Nothing
     * Modifies: *this
     * Effects:  Default initalizes the Game object
     *           gameBoard = standard Board
     *           numTurns = 0
     */
    Game();

    /*
     * Requies: Nothing
     * Modifies: *this
     * Effects:  Adds the 2 palyers names;
     *
    getPlayerNames(); */

    /*
     * Requires: numTurns is initalized
     * Modifies: Nothing
     * Effects:  Returns numTurns
     */
    int getNumTurns() const;

    /*
     * Requires: numTirns is initalized 
     * Modifies: Nothing
     * Effects:  Returns the the palyer who is up next using moduolo
     */
    int getPlayerTurn() const;

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Makes a move on the board.
     *           If move is legal updates turn
     *           If move is illegal states the move is illegal
     *           Returns result of move
     */
    Result makeMove();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Gets player input and returns, does not validate and does not actually make move
     */
    virtual choice getPlay();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Plays a full game on gameBoard
     */
    void playGame();

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns the name of the indicated player
     */
    std::string getPlayerName(int player);

private:
    Board gameBoard;
    int numTurns;
    std::string p1Name;
    std::string p2Name;
};

class AIGame : public Game {
public:
    /*
     * Requires: Nothing
     * Modifies: *this
     * Effects:  If isAI and assign are true assignTo must be either 1 or 2;
     */
    AIGame(bool isAI, bool assign = false, int assignTo = 0);

    /*
     * Requires: Nothing
     * Modifies: Nothing
     * Effects:  Returns thr turn of the player. If it is an AI says where played
     *           Otherise prompts for position
     */
    virtual choice getPlay();

private:
    int numAI;
    AI *theAI;
};
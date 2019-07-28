#include <iostream>
#include <string>

#include "Board.h"
#include "AI.h"

using namespace std;

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects:  Is the shell of the game allowing the user to play against the AI
 */
void AIPlay();

/*
 * Requires: Nothing
 * Modifies: Nothing
 * Effects:  Is the shell of the game allowing the user to play against another human
 */
void terminalPlay();

/* Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the board prepared for two player use.
 */
Board getBoard(string & p1, string & p2);

/* Requires: Nothing
 * Modifies: Nothing
 * Effects: Returns the board prepared for single player use.
 */
Board getBoardAI(string & p1);

int main() {
    int userInput;

    cout << "If you want to play two player tic-tac-toe press 1, if you want to play against an AI press 2. ";
    cin >> userInput;
    if (userInput == 1) {
        terminalPlay();
    } else {
        AIPlay();
    }
    return 0;
}

void AIPlay() {
    Board currentBoard;
    string player1Name;
    int currentPlayer;
    int userInput;
    Result moveResult = NoResult;
    string trash = "";
    int rowChoice;
    int colChoice;

    // Prepares the game board
    currentBoard = getBoardAI(player1Name);

    // Sets who will go first
    if (rand() % 2 == 0) {
        cout << "The AI will play as player 1. " << endl;
        currentBoard.changeStartingPlayer();
    } else {
        cout << "You will play as player 1. " << endl;
    }

    // Repats the game process until someone wins or draws
    while (moveResult == NoResult || moveResult == IllegalMove) {
        currentPlayer = currentBoard.toMove();
        currentBoard.printBoard(cout);

        // Asks for player or AI input depending on the turn
        if (currentPlayer == 1) {
            cout << player1Name << ", please enter your move: ";
            cin >> userInput;
            getline(cin, trash);
        } else {
            userInput = AI(currentBoard);
        }

        // While the input is trash or not correct force the player to go again
        // This will never effect the AI player and is therefore only organized 
        // for the user
        while (trash != "" || cin.fail() || userInput > 9 || userInput < 1) {
            trash = "";
            if (cin.fail()) {
                cin.clear();
                string s;
                getline(cin, s);
            }
            moveResult = IllegalMove;
            cout << "ILLEGAL MOVE: Try again";
            currentBoard.printBoard(cout);
            cout << player1Name << ", please enter your move: ";
            cin >> userInput;
            getline(cin, trash);
        }

        // Extrapolate the row and column that is being played
        userInput -= 1;
        rowChoice = userInput / 3;
        colChoice = userInput % 3;

        // Makes move and, if illefal, notifies user
        moveResult = currentBoard.makeMove(rowChoice, colChoice);
        if (moveResult == IllegalMove) {
            cout << "ILLEGAL MOVE: Try again" << endl;
        }
    }

    // Reached at end of game and notifies of outcome
    if (moveResult == Win) {
        cout << "Congratulations ";
        if (currentBoard.toMove() == 1) {
            cout << player1Name;
        } else {
            cout << "AI";
        }
        cout << "! You win! " << endl;
    } else {
        cout << "Draw! " << endl;
    }
    // Prints final board
    currentBoard.printBoard(cout);
    return;
}

void terminalPlay() {
    Board currentBoard;
    string player1Name;
    string player2Name;
    int currentPlayer;
    int userInput;
    Result moveResult = NoResult;
    string trash = "";
    int rowChoice;
    int colChoice;

    // Prepares game board
    currentBoard = getBoard(player1Name, player2Name);

    // Plays the game alternating on good user input
    while (moveResult == NoResult || moveResult == IllegalMove) {
        // Prints board and asked for user input
        currentPlayer = currentBoard.toMove();
        currentBoard.printBoard(cout);
        if (currentPlayer == 1) {
            cout << player1Name;
        } else {
            cout << player2Name;
        }
        cout << ", please enter your move: ";
        cin >> userInput;
        getline(cin, trash);

        // If input is bad force user to enter good input
        while (trash != "" || cin.fail() || userInput > 9 || userInput < 1) {
            trash = "";
            if (cin.fail()) {
                cin.clear();
                string s;
                getline(cin, s);
            }
            moveResult = IllegalMove;
            cout << "ILLEGAL MOVE: Try again" << endl;
            currentBoard.printBoard(cout);
            if (currentBoard.toMove() == 1) {
                cout << player1Name;
            } else {
                cout << player2Name;
            }

            cout << ", please enter your move: ";
            cin >> userInput;
            getline(cin, trash);
        }

        // Extrapolates row and column played by the user
        userInput -= 1;
        rowChoice = userInput / 3;
        colChoice = userInput % 3;

        // Make the move and notify of bad move
        moveResult = currentBoard.makeMove(rowChoice, colChoice);
        if (moveResult == IllegalMove) {
            cout << "ILLEGAL MOVE: Try again" << endl;
        }
    }

    // Ends game and notifies of results
    if (moveResult == Win) {
        cout << "Congratulations ";
        if (currentBoard.toMove() == 1) {
            cout << player1Name;
        } else {
            cout << player2Name;
        }
        cout << "! You win! " << endl;
    } else {
        cout << "Draw! " << endl;
    }
    currentBoard.printBoard(cout);
    return;
}

Board getBoard(string & p1, string & p2) {
    // Clears buffer
    string s;
    getline(cin, s);
    // Gets names
    cout << "Player 1, please enter your name: ";
    getline(cin, p1);
    cout << "Player 2, please enter your name: ";
    getline(cin, p2);
    // Vreates board and returns
    Board board;
    return board;
}

Board getBoardAI(string & p1) {
    // Clears buffer
    string s;
    getline(cin, s);
    // Gets name
    cout << "Please enter your name: ";
    getline(cin, p1);
    // Creates boarrd and returns
    Board board;
    return board;
}

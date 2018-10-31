#include <iostream>
#include <string>

#include "Board.h"
#include "AI.h"

using namespace std;

void AIPlay();
void terminalPlay();
Board getBoard(string & p1, string & p2);
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

    currentBoard = getBoardAI(player1Name);

    if (rand() % 2 == 0) {
        cout << "The AI will play as player 1. " << endl;
        currentBoard.changeStartingPlayer();
    } else {
        cout << "You will play as player 1. " << endl;
    }

    while (moveResult == NoResult || moveResult == IllegalMove) {
        currentPlayer = currentBoard.toMove();
        currentBoard.printBoard(cout);

        if (currentPlayer == 1) {
            cout << player1Name << ", please enter your move: ";
            cin >> userInput;
            getline(cin, trash);
        } else {
            userInput = AI(currentBoard);
        }

        while (trash != "" || cin.fail() || userInput > 9 || userInput < 1) {
            trash = "";
            if (cin.fail()) {
                cin.clear();
                string s;
                getline(cin, s);
            }
            moveResult == IllegalMove;
            cout << "ILLEGAL MOVE: Try again";
            currentBoard.printBoard(cout);
            cout << player1Name << ", please enter your move: ";
            cin >> userInput;
            getline(cin, trash);
        }

        userInput -= 1;
        rowChoice = userInput / 3;
        colChoice = userInput % 3;

        moveResult = currentBoard.makeMove(rowChoice, colChoice);
        if (moveResult == IllegalMove) {
            cout << "ILLEGAL MOVE: Try again" << endl;
        }
    }

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

    currentBoard = getBoard(player1Name, player2Name);

    while (moveResult == NoResult || moveResult == IllegalMove) {
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
        while (trash != "" || cin.fail() || userInput > 9 || userInput < 1) {
            trash = "";
            if (cin.fail()) {
                cin.clear();
                string s;
                getline(cin, s);
            }
            moveResult == IllegalMove;
            cout << "ILLEGAL MOVE: Try again";
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
        userInput -= 1;
        rowChoice = userInput / 3;
        colChoice = userInput % 3;

        moveResult = currentBoard.makeMove(rowChoice, colChoice);
        if (moveResult == IllegalMove) {
            cout << "ILLEGAL MOVE: Try again" << endl;
        }
    }

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
    string s;
    getline(cin, s);
    cout << "Player 1, please enter your name: ";
    getline(cin, p1);
    cout << "Player 2, please enter your name: ";
    getline(cin, p2);
    Board board;
    return board;
}

Board getBoardAI(string & p1) {
    string s;
    getline(cin, s);
    cout << "Please enter your name: ";
    getline(cin, p1);
    Board board;
    return board;
}

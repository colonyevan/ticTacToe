#include "Game.h"
#include "unit_test_framework.h"

#include <sstream>

using namespace std;

TEST(testDefaultCtor) {
    Game g1;

    ostringstream expected;
    ostringstream actual;

    g1.getGameBoard()->printBoard(actual);
    Board().printBoard(expected);

    ASSERT_EQUAL(actual.str(), expected.str());
    ASSERT_EQUAL(g1.getNumTurns(), 0);
}

TEST(testGetPlayerNames) {
    Game g1;
    ostringstream trash;
    istringstream input("Alice Bob");

    g1.getPlayerNames(input, trash);

    ASSERT_EQUAL(g1.getPlayerName(1), "Alice");
    ASSERT_EQUAL(g1.getPlayerName(2), "Bob");
}

TEST(testGetPlayerTurn) {
    Game g1;

    ostringstream trash;
    istringstream input("1");

    ASSERT_EQUAL(g1.getPlayerTurn(), 1);
    g1.makeMove(input, trash);
    ASSERT_EQUAL(g1.getPlayerTurn(), 2);
}

TEST(testMakeMove) {
    Game g1;
    istringstream starter("Alice Bob");
    g1.getPlayerNames(starter);
    ostringstream output;
    ostringstream expected;
    istringstream input("1");
    Result test = g1.makeMove(input, output);

    expected << "      1 | 2 | 3" << endl
             << "     ---+---+---" << endl
             << "      4 | 5 | 6" << endl
             << "     ---+---+---" << endl
             << "      7 | 8 | 9" << endl
             << "Alice, please enter your move: " << endl;
    ASSERT_EQUAL(expected.str(), output.str());
    ASSERT_EQUAL(g1.getNumTurns(), 1);
    ASSERT_EQUAL(NoResult, test);

    output.clear();
    expected.clear();
    input.clear();
    input.str("2");

    test = g1.makeMove(input, output);

    expected << "      X | 2 | 3" << endl
             << "     ---+---+---" << endl
             << "      4 | 5 | 6" << endl
             << "     ---+---+---" << endl
             << "      7 | 8 | 9" << endl
             << "Bob, please enter your move: " << endl;
    ASSERT_EQUAL(expected.str(), output.str());
    ASSERT_EQUAL(g1.getNumTurns(), 2);
    ASSERT_EQUAL(NoResult, test);

    output.clear();
    expected.clear();
    input.clear();
    input.str("2");

    test = g1.makeMove(input, output);

    expected << "      X | 2 | 3" << endl
             << "     ---+---+---" << endl
             << "      4 | 5 | 6" << endl
             << "     ---+---+---" << endl
             << "      7 | 8 | 9" << endl
             << "Alice, please enter your move: "
             << "That as an ilegal move, try again! " << endl;
    ASSERT_EQUAL(expected.str(), output.str());
    ASSERT_EQUAL(g1.getNumTurns(), 2);
    ASSERT_EQUAL(IllegalMove, test);
}

TEST_MAIN()
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
    istringstream input("Alice Bob");

    ASSERT_EQUAL(g1.getPlayerTurn(), 1);
    g1.makeMove();
    ASSERT_EQUAL(g1.getPlayerTurn(), 2);
}

TEST_MAIN()
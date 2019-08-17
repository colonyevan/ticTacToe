#include "AI.h"
#include "Board.h"
#include "unit_test_framework.h"

using namespace std;

TEST(testWinningMove) {
    Board b1("XOOEXEEXO");

    AI *test = AIFactory(3);

    int result = test->getMove(&b1, Player1);

    ASSERT_EQUAL(result, 6);

    delete test;
}

TEST(testWinningMoveTwo) {
    Board b1("XEXEOEEOX");

    AI *test = AIFactory(3);

    int result = test->getMove(&b1, Player2);

    ASSERT_EQUAL(result, 2);

    delete test;
}

TEST_MAIN()
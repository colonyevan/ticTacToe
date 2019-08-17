#include "AI.h"
#include "Board.h"
#include "unit_test_framework.h"

using namespace std;

TEST(testWinningMove) {
    Board b1("XOOEXEEXO");

    AI* test = AIFactory(3);

    int result = test->getMove(&b1, Player1);

    ASSERT_EQUAL(result, 6);
}

TEST_MAIN()
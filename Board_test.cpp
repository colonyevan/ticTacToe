#include "Board.h"
#include "unit_test_framework.h"

#include <sstream>

using namespace std;

TEST(testDefaultCtor) {
    Board b1;
    ostringstream expected;
    ostringstream actual;

    expected << "      1 | 2 | 3" << endl << "     ---+---+---" << endl << "      4 | 5 | 6" << endl << "     ---+---+---" << endl << "      7 | 8 | 9" << endl;

    b1.printBoard(actual);

    ASSERT_EQUAL(expected.str(), actual.str());
}

TEST(testCopyCtorEasy) {
    Board b1;
    Board b2(b1);
    ostringstream expected;
    ostringstream actual;

    expected << "      1 | 2 | 3" << endl << "     ---+---+---" << endl << "      4 | 5 | 6" << endl << "     ---+---+---" << endl << "      7 | 8 | 9" << endl;

    b2.printBoard(actual);

    ASSERT_EQUAL(expected.str(), actual.str());
}

TEST(testCopyCtorMedium) {
    Board b1;
    b1.makeMove(1, 1, Player1);
    b1.makeMove(0, 0, Player2);
    Board b2(b1);
    ostringstream expected;
    ostringstream actual;

    expected << "      O | 2 | 3" << endl << "     ---+---+---" << endl << "      4 | X | 6" << endl << "     ---+---+---" << endl << "      7 | 8 | 9" << endl;

    b2.printBoard(actual);

    ASSERT_EQUAL(expected.str(), actual.str());
}

TEST(testCopyCtorHard) {
    Board b1;
    b1.makeMove(1, 1, Player1);
    b1.makeMove(0, 0, Player2);
    b1.makeMove(1, 0, Player1);
    b1.makeMove(0, 1, Player2);
    b1.makeMove(2, 2, Player1);
    b1.makeMove(0, 2, Player2);
    b1.makeMove(2, 0, Player1);
    b1.makeMove(2, 1, Player2);
    b1.makeMove(1, 2, Player1);
    Board b2(b1);
    ostringstream expected;
    ostringstream actual;

    expected << "      O | O | O" << endl << "     ---+---+---" << endl << "      X | X | X" << endl << "     ---+---+---" << endl << "      X | O | X" << endl;

    b2.printBoard(actual);

    ASSERT_EQUAL(expected.str(), actual.str());
}

TEST(testStringCtor) {
    Board b1("XOOOXXOXO");
    Board b2("XEEOEEXOX");
    ostringstream expected1;
    ostringstream actual1;
    ostringstream expected2;
    ostringstream actual2;


    expected1 << "      X | O | O" << endl << "     ---+---+---" << endl << "      O | X | X" << endl << "     ---+---+---" << endl << "      O | X | O" << endl;
    expected2 << "      X | 2 | 3" << endl << "     ---+---+---" << endl << "      O | 5 | 6" << endl << "     ---+---+---" << endl << "      X | O | X" << endl;

    b1.printBoard(actual1);
    b2.printBoard(actual2);

    ASSERT_EQUAL(expected1.str(), actual1.str());

    ASSERT_EQUAL(expected2.str(), actual2.str());
}

TEST(testMakeMove) {
    Board b1;
    Result temp;
    temp = b1.makeMove(0, 0, Player1);
    ASSERT_EQUAL(temp, NoResult);
    temp = b1.makeMove(0, 0, Player2);
    ASSERT_EQUAL(temp, IllegalMove);
    temp = b1.makeMove(1, 0, Player1);
    ASSERT_EQUAL(temp, NoResult);
    temp = b1.makeMove(2, 0, Player1);
    ASSERT_EQUAL(temp, Win);
    b1.makeMove(0, 1, Player2);
    b1.makeMove(1, 1, Player2);
    b1.makeMove(2, 1, Player2);
    b1.makeMove(0, 2, Player2);
    b1.makeMove(1, 2, Player2);
    temp = b1.makeMove(2, 2, Player1);
    ASSERT_EQUAL(temp, Draw);
}

TEST(testInBounds) {
    Board b1;
    ASSERT_FALSE(b1.inBounds(1, 3));
    ASSERT_FALSE(b1.inBounds(-1, 2));
    ASSERT_FALSE(b1.inBounds(4, 2));
    ASSERT_TRUE(b1.inBounds(1, 2));
}

TEST(isBoardFull) {
    Board b1;
    ASSERT_FALSE(b1.isBoardFull());
    b1.makeMove(1, 1, Player1);
    b1.makeMove(0, 0, Player2);
    b1.makeMove(1, 0, Player1);
    b1.makeMove(0, 1, Player2);
    b1.makeMove(2, 2, Player1);
    b1.makeMove(0, 2, Player2);
    b1.makeMove(2, 0, Player1);
    b1.makeMove(2, 1, Player2);
    b1.makeMove(1, 2, Player1);
    ASSERT_TRUE(b1.isBoardFull());
}

TEST(testPiecesInDirection) {
    Board b1;

    ASSERT_EQUAL(b1.piecesInDirection(1, 1, 1, 0), 1);
    ASSERT_EQUAL(b1.piecesInDirection(0, 0, 1, 0), 2);
    b1.makeMove(1, 1, Player1);
    ASSERT_EQUAL(b1.piecesInDirection(1, 1, -1, 0), 0);
    b1.makeMove(0, 0, Player1);
    ASSERT_EQUAL(b1.piecesInDirection(1, 1, -1, -1), 1);
    b1.makeMove(2, 2, Player1);
    ASSERT_EQUAL(b1.piecesInDirection(2, 2, -1, -1), 2);
}

TEST(testIsWin) {
    Board b1("OOXOXXOXO");
    ASSERT_TRUE(b1.isWin(0, 0));
    ASSERT_FALSE(b1.isWin(1, 1));
    ASSERT_FALSE(b1.isWin(1, 2));
    ASSERT_FALSE(b1.isWin(2, 2));
    Board b2("OXXOXOXOO");
    ASSERT_TRUE(b2.isWin(2, 0));
    ASSERT_TRUE(b2.isWin(1, 1));
    ASSERT_TRUE(b2.isWin(0, 2));
    ASSERT_FALSE(b2.isWin(0, 1));
    ASSERT_FALSE(b2.isWin(0, 0));
}

TEST(testGetOpenSpaces) {
    Board b1("XEEOEEXOX");
}

TEST_MAIN()
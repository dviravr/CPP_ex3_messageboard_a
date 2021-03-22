/**
 * AUTHORS: dvir avrahami
 * 
 * Date: 2021-03
 */

#include "Board.hpp"
#include "doctest.h"
using namespace ariel;
using ariel::Direction;

#include <algorithm>
#include <string>
using namespace std;

Board board;

TEST_CASE("Test post and read") {
    CHECK(board.read(0, 0, Direction::Vertical, 5) == "_____");
    CHECK(board.read(5, 5, Direction::Vertical, 0) == "");
    CHECK(board.read(10, 10, Direction::Horizontal, 3) == "___");
    board.post(3, 3, Direction::Vertical, "Hello world!");
    CHECK(board.read(3, 3, Direction::Vertical, 12) == "Hello world!");
    CHECK(board.read(4, 1, Direction::Horizontal, 12) == "__e_________");
    board.post(6, 1, Direction::Horizontal, "CPP course");
    CHECK(board.read(3, 3, Direction::Vertical, 12) == "HelPo world!");
    board.post(6, 6, Direction::Vertical, "0");
    CHECK(board.read(6, 1, Direction::Horizontal, 10) == "CPP c0urse");
    board.post(100, 100, Direction::Horizontal, "need bigger board");
    CHECK(board.read(100, 105, Direction::Horizontal, 12) == "bigger board");
    CHECK(board.read(500, 500, Direction::Vertical, 3) == "___");
    board.post(3000, 3, Direction::Horizontal, "ABCDEFG");
    CHECK(board.read(3000, 3, Direction::Horizontal, 7) != "ABCOEFG");
    board.post(3000, 6, Direction::Vertical, "O");
    CHECK(board.read(3000, 3, Direction::Horizontal, 7) == "ABCOEFG");
    board.post(50, 50, Direction::Horizontal, "hey");
    board.post(49, 51, Direction::Vertical, "AAA");
    CHECK(board.read(50, 50, Direction::Horizontal, 3) != "hey");
    CHECK(board.read(49, 51, Direction::Vertical, 4) != "AAA");
    CHECK(board.read(49, 51, Direction::Vertical, 3) == "AAA");
    board.post(51, 51, Direction::Vertical, "BBB");
    CHECK(board.read(51, 51, Direction::Vertical, 3) == "BBB");
    board.post(1000, 1, Direction::Horizontal, "bash grade 100");
    CHECK(board.read(1000, 1, Direction::Horizontal, 4) == "bash");
    CHECK(board.read(1000, 6, Direction::Horizontal, 5) == "grade");
    CHECK(board.read(1000, 12, Direction::Horizontal, 3) == "100");
    board.post(1000, 0, Direction::Horizontal, "bash grade 100");
    CHECK(board.read(1000, 0, Direction::Horizontal, 15) == "bash grade 1000");
    board.post(998, 0, Direction::Vertical, "hello it's me again");
    CHECK(board.read(1000, 0, Direction::Horizontal, 4) == "lash");
}

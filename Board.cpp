#include "Board.hpp"

#include <iostream>
#include <vector>

#include "Direction.hpp"

using ariel::Direction;
using namespace std;
using namespace ariel;

Board::Board() {
    str = "board";
}

void Board::post(uint row, uint col, Direction dir, string const &msg) {
}

string Board::read(uint row, uint col, Direction dir, uint msgLen) {
    return str;
}

void Board::show() {
}

Board::~Board() {
}
#include "Board.hpp"

#include <iostream>
#include <vector>

#include "Direction.hpp"

using ariel::Direction;
using namespace std;
using namespace ariel;

Board::Board() {
    _rows = 100;
    _cols = 100;
    cout << "Bourd()" << endl;
}

Board::Board(uint rows, uint cols) {
    _rows = rows;
    _cols = cols;
}

void Board::post(uint row, uint col, Direction dir, string const &msg) {
}

string Board::read(uint row, uint col, Direction dir, uint msgLen) {
    return "board";
}

void Board::show() {
}

Board::~Board() {
}
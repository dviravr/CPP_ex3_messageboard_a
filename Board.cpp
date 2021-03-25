#include "Board.hpp"

#include <iostream>
#include <vector>

#include "Direction.hpp"

using ariel::Direction;
using namespace std;
using namespace ariel;

void Board::post(uint row, uint col, Direction dir, string const &msg) {
    // loop over the message and post every char on the board
    for (uint i = 0; i < msg.length(); i++) {
        if (dir == Direction::Vertical) {
            _board[row + i][col] = msg[i];
        } else if (dir == Direction::Horizontal) {
            _board[row][col + i] = msg[i];
        }
    }
    // update the last index
    _lastRow = row;
    _lastCol = col;
}

string Board::read(uint row, uint col, Direction dir, uint msgLen) {
    string str;
    for (uint i = 0; i < msgLen; i++) {
        if (dir == Direction::Vertical) {
            // check if there is a char in this index,
            // if so add it to the string else add _ to the string
            if (_board[row + i][col] != 0) {
                str += _board[row + i][col];
            } else {
                str += "_";
            }
        } else if (dir == Direction::Horizontal) {
            if (_board[row][col + i] != 0) {
                str += _board[row][col + i];
            } else {
                str += "_";
            }
        }
    }
    return str;
}

void Board::show() {
    const uint rowsToShow = 40;
    const uint colsToShow = 150;
    uint startRow = 0;
    uint startCol = 0;
    if (_lastRow > rowsToShow / 2) {
        startRow = _lastRow - rowsToShow / 2;
    }
    if (_lastCol > colsToShow / 2) {
        startCol = _lastCol - colsToShow / 2;
    }
    for (uint i = startRow; i < rowsToShow + startRow; i++) {
        for (uint j = startCol; j < colsToShow + startCol; j++) {
            if (_board[i][j] != 0) {
                cout << _board[i][j];
            } else {
                cout << "_";
            }
        }
        cout << endl;
    }
}

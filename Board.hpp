#pragma once
#include <iostream>
#include <unordered_map>

#include "Direction.hpp"
using ariel::Direction;

using namespace std;

namespace ariel {
class Board {
   private:
    // hash inside hash to represent the board, the first hash is the rows and the second is the columns
    unordered_map<uint, unordered_map<uint, char>> _board;
    // last post index for the show()
    uint _lastRow, _lastCol;

   public:
    // defult last indexes
    Board() {
        _lastRow = 20;
        _lastCol = 75;
    }
    void post(uint row, uint col, Direction dir, string const &msg);
    string read(uint row, uint col, Direction dir, uint msgLen);
    void show();
};
}  // namespace ariel

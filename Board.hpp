#pragma once
#include <iostream>
#include <vector>

#include "Direction.hpp"
using ariel::Direction;

using namespace std;

namespace ariel {
class Board {
   private:
    uint _rows, _cols;
    vector<vector<char>> _board;

   public:
    Board();
    Board(uint rows, uint cols);
    ~Board();
    uint getRows() { return _rows; }
    uint getCols() { return _cols; }
    void post(uint row, uint col, Direction dir, string const &msg);
    string read(uint row, uint col, Direction dir, uint msgLen);
    void show();
};
}  // namespace ariel

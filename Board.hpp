#pragma once
#include <iostream>
#include <vector>

#include "Direction.hpp"
using ariel::Direction;

using namespace std;

namespace ariel {
class Board {
   private:
    vector<vector<char>> _board;
    string str;

   public:
    Board();
    ~Board();
    void post(uint row, uint col, Direction dir, string const &msg);
    string read(uint row, uint col, Direction dir, uint msgLen);
    void show();
};
}  // namespace ariel

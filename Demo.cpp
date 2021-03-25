/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	board.show();
	board.post(/*row=*/100, /*column=*/200, Direction::Vertical, "hello world");
	cout << board.read(/*row=*/100, /*column=*/200, Direction::Vertical, /*length=*/5) << endl;  
	board.show();
	board.post(/*row=*/	1000, /*column=*/200000, Direction::Horizontal, "bash grade 100");
	cout << board.read(/*row=*/1000, /*column=*/200007, Direction::Horizontal, /*length=*/1) << endl;  


	board.show(); // shows the board in a reasonable way. For example:
		//    98:  _________
		//    99:  ____x____
		//    100: __abyd___
		//    101: ____z____
		//    102: _________
}


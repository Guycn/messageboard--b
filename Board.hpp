

#include <iostream>
#include <vector>
#include <string>
#include "Direction.hpp"
using namespace std;

namespace ariel{
    class Board{
        public:
            std::vector<std::vector<char>> board;
        
        public:
            Board();
            Board(unsigned int row,unsigned int col);
            void post(unsigned int row, unsigned int col, Direction shape, string const & notice);
            string read(unsigned int row, unsigned int col, Direction shape, unsigned int lenght);
            void show();
    };

    
}
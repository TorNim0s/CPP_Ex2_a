#include "Direction.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    class Notebook
    {
    private:
        // hashmap page -> 2 dimention array that will grow as we go || or || to a linked list for each row.
        
    public:
        void write(int page, int row, int col, Direction direction, string const &sentence);
        static string read(int page, int row, int col, Direction direction, int length);
        void erase(int page, int row, int col, Direction direction, int length);
        void show(int page_to_show);
    };
    
}
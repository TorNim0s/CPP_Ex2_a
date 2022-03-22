#include <stdexcept>
#include "doctest.h"
#include "Notebook.hpp"

#define TEST_TEXT "Test"

using namespace ariel;
using namespace std;

Notebook notebook;

TEST_CASE("Good checks")
{
    /*
    ----------Vertical------------
    */

    notebook.write(0, 0, 0, Direction::Vertical, TEST_TEXT);

    CHECK(notebook.read(0, 0, 0, Direction::Vertical, sizeof(TEST_TEXT)) == TEST_TEXT);

    // check to add on existing place on the notebook
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 1, 0, Direction::Vertical, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 2, 0, Direction::Vertical, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 3, 0, Direction::Vertical, TEST_TEXT));

    /*
    ------------------Horizontal--------------
    */
    notebook.write(0, 0, 1, Direction::Horizontal, TEST_TEXT);

    CHECK(notebook.read(0, 0, 1, Direction::Horizontal, sizeof(TEST_TEXT)) == TEST_TEXT);

    // check to add on existing place on the notebook
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Horizontal, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Horizontal, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 0, 3, Direction::Horizontal, TEST_TEXT));
    CHECK_THROWS(notebook.write(0, 0, 4, Direction::Horizontal, TEST_TEXT));

    /*
    ----------- earse check---------
    */

   notebook.erase(0,0,0, Direction::Vertical, sizeof(TEST_TEXT));
   CHECK(notebook.read(0,0,0,Direction::Vertical, sizeof(TEST_TEXT)) == "~~~~");

   notebook.erase(0,0,1, Direction::Horizontal, sizeof(TEST_TEXT));
   CHECK(notebook.read(0,0,1,Direction::Horizontal, sizeof(TEST_TEXT)) == "~~~~");
}

TEST_CASE("Bad Input"){
    CHECK_THROWS(notebook.write(-1,0,0,Direction::Vertical, TEST_TEXT));
    CHECK_THROWS(notebook.write(0,-1,0,Direction::Vertical, TEST_TEXT));
    CHECK_THROWS(notebook.write(0,0,-1,Direction::Vertical, TEST_TEXT));

    // Horizontal is the same

    CHECK_THROWS(notebook.read(-1,0,0,Direction::Vertical, sizeof(TEST_TEXT)));
    CHECK_THROWS(notebook.read(0,-1,0,Direction::Vertical, sizeof(TEST_TEXT)));
    CHECK_THROWS(notebook.read(0,0,-1,Direction::Vertical, sizeof(TEST_TEXT)));

    // Horizontal is the same

    CHECK_THROWS(notebook.erase(-1,0,0,Direction::Vertical, sizeof(TEST_TEXT)));
    CHECK_THROWS(notebook.erase(0,-1,0,Direction::Vertical, sizeof(TEST_TEXT)));
    CHECK_THROWS(notebook.erase(0,0,-1,Direction::Vertical, sizeof(TEST_TEXT)));

    // check length is lower than 0

    CHECK_THROWS(notebook.read(5,5,5,Direction::Vertical, -4));
    CHECK_THROWS(notebook.erase(5,5,5,Direction::Vertical, -4));

}
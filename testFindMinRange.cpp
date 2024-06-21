/*****************************************************************************/
/* Name:     testFindMinRange.cpp                                            */
/*                                                                           */
/* Purpose:  Ensures correct functionality.                                  */
/*           Validates with various list configurations.                     */
/*           Checks outputs against expected results.                        */
/*           Confirms passed tests.                                          */
/*                                                                           */
/*****************************************************************************/


#include "findMinRange.h"
#include <iostream>
#include <vector>
#include <cassert>

void runTests() {
    MinRangeFinder finder;

    {
        std::vector<std::vector<int>> lists = {
            {1, 2, 12},
            {-1, 4, 7, 11},
            {3, 8, 10}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 2 && result.second == 4);
        std::cout << "Test 1 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {4, 10, 15, 24, 26},
            {0, 9, 12, 20},
            {5, 18, 22, 30}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 20 && result.second == 24);
        std::cout << "Test 2 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 4 && result.second == 9);
        std::cout << "Test 3 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {1},
            {2},
            {3}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 1 && result.second == 3);
        std::cout << "Test 4 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {10, 15, 25},
            {0, 9, 12, 20, 23},
            {18, 22, 30}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 22 && result.second == 25);
        std::cout << "Test 5 passed\n";
    }

    // Additional test cases with a variable number of lists
    {
        std::vector<std::vector<int>> lists = {
            {1, 5, 8, 12},
            {4, 6},
            {7, 8, 10, 15},
            {2, 3, 14, 16}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 3 && result.second == 7);
        std::cout << "Test 6 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {1, 5, 8},
            {4, 10, 12},
            {3, 6, 9, 15},
            {2, 11, 13}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 1 && result.second == 4);
        std::cout << "Test 7 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {1, 3, 5, 7, 9},
            {2, 4, 6, 8, 10},
            {0, 11, 12, 13}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 0 && result.second == 2);
        std::cout << "Test 8 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 3}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 1 && result.second == 1);
        std::cout << "Test 9 passed\n";
    }

    {
        std::vector<std::vector<int>> lists = {
            {-10, -5, 0, 5, 10},
            {1, 2, 3, 4, 5},
            {-3, -2, -1, 6, 7}
        };
        auto result = finder.findMinRange(lists);
        assert(result.first == 5 && result.second == 6);
        std::cout << "Test 10 passed\n";
    }
}

int main() {
    runTests();
    std::cout << "All tests passed!\n";
    return 0;
}

/*****************************************************************************/
/* Name:     main.cpp                                                        */
/*                                                                           */
/* Purpose:  Gets number of lists and their elements.                        */
/*           Parses input into a vector of integer lists.                    */
/*           Uses MinRangeFinder to determine the smallest                   */
/*           range covering all lists.                                       */
/*           Displays the smallest range.                                    */
/*                                                                           */
/*****************************************************************************/


#include "findMinRange.h"
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int numLists;
    std::cout << "Enter the number of lists: ";
    std::cin >> numLists;
    std::cin.ignore(); // Ignore the newline character after the number of lists

    std::vector<std::vector<int>> lists(numLists);

    for (int i = 0; i < numLists; ++i) {
        std::string line;
        std::cout << "Enter elements of list " << i + 1 << " separated by commas: ";
        std::getline(std::cin, line);
        std::istringstream stream(line);
        std::string numberStr;
        while (std::getline(stream, numberStr, ',')) {
            std::istringstream numberStream(numberStr);
            int number;
            numberStream >> number;
            lists[i].push_back(number);
        }
    }

    MinRangeFinder finder;
    auto result = finder.findMinRange(lists);
    std::cout << "The smallest range is [" << result.first << ", " << result.second << "]\n";

    return 0;
}

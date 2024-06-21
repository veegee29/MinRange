/*****************************************************************************/
/* Name:     findMinRange.cpp                                                */
/*                                                                           */
/* Purpose:  Declares the MinRangeFinder class and methods.                  */
/*           Provides an interface for finding the minimal range.            */
/*                                                                           */
/*****************************************************************************/


#ifndef FINDMINRANGE_H
#define FINDMINRANGE_H

#include <vector>
#include <utility>
#include <queue>
#include <limits>

class MinRangeFinder {
private:
    class Element {
    public:
        int value;
        int listIndex;
        int elementIndex;

        Element(int value, int listIndex, int elementIndex)
            : value(value), listIndex(listIndex), elementIndex(elementIndex) {}

        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };

    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
    int maxElement = std::numeric_limits<int>::min();
    int minRange = std::numeric_limits<int>::max();
    int start = -1;
    int end = -1;

public:
    std::pair<int, int> findMinRange(const std::vector<std::vector<int>>& lists);
};

#endif // FINDMINRANGE_H

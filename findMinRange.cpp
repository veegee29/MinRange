/*****************************************************************************/
/* Name:     findMinRange.cpp                                                */
/*                                                                           */
/* Purpose:  Implements MinRangeFinder class.                                */
/*           Defines algorithm to find the minimal range covering all lists. */
/*                                                                           */
/*****************************************************************************/


#include "findMinRange.h"

std::pair<int, int> MinRangeFinder::findMinRange(const std::vector<std::vector<int>>& lists) {
    while (!minHeap.empty()) {
        minHeap.pop();
    }
    maxElement = std::numeric_limits<int>::min();
    minRange = std::numeric_limits<int>::max();
    start = -1;
    end = -1;

    for (size_t i = 0; i < lists.size(); ++i) {
        if (!lists[i].empty()) {
            minHeap.push(Element(lists[i][0], static_cast<int>(i), 0));
            maxElement = std::max(maxElement, lists[i][0]);
        }
    }

    while (!minHeap.empty()) {
        auto minElement = minHeap.top();
        minHeap.pop();

        int currentRange = maxElement - minElement.value;
        if (currentRange < minRange) {
            minRange = currentRange;
            start = minElement.value;
            end = maxElement;
        }

        if (minElement.elementIndex + 1 < lists[minElement.listIndex].size()) {
            int nextIndex = minElement.elementIndex + 1;
            auto nextElement = Element(lists[minElement.listIndex][nextIndex], minElement.listIndex, nextIndex);
            minHeap.push(nextElement);
            maxElement = std::max(maxElement, nextElement.value);
        } else {
            break;
        }
    }

    return {start, end};
}

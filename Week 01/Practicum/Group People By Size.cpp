#include <vector>
#include <algorithm>
#include <iostream>

// O(n^2) solution
/* Logic:
 *  For each character in the jewels string, find the number of times the character appears in the stones string.
 */

// O(n*log(n)) solution
/* Logic:
    * We want to sort the array by group size.
    * In order not to lose their original positions, we will store the original positions in a pair. 
    * When the array is sorted, the logic is the following:
    * 1. We count how many people are added in the current group.
    * 2. If the current group is full, we move to the next group.
    * 3. We take the current person group in the check, because we know that the array is sorted by group size and there are enough to form each group.

    * Notes: 
    * * Dont forget to add the vector when creating a new group. Or you will get a segmentation fault.
 */
class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::vector<std::pair<int, int>> positionsByGroupSize;

        for(int i = 0; i < groupSizes.size(); i++) {
            positionsByGroupSize.push_back({groupSizes[i], i});
        }

        std::sort(positionsByGroupSize.begin(),positionsByGroupSize.end());

        std::vector<std::vector<int>> solution;

        int currentGroup = 0;
        int currentGroupIndex = 0;
        for(int i = 0; i < groupSizes.size(); i++) {
            int myGroupSize = positionsByGroupSize[i].first;

            if (solution.size() <= currentGroup) {
                solution.push_back(std::vector<int>());
            }

            solution[currentGroup].push_back(positionsByGroupSize[i].second);
            currentGroupIndex++;

            if (currentGroupIndex >= myGroupSize) {
                currentGroup++;
                currentGroupIndex = 0;
            }
        }

        return solution;
    }
};
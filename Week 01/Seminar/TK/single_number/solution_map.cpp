#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> countMap;

        for (int num : nums)
        {
            countMap[num]++;
        }

        for (const auto &pair : countMap)
        {
            if (pair.second == 1)
            {
                return pair.first;
            }
        }

        return 0;
    }
};
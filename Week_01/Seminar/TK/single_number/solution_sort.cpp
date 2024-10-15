#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
        {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }

        return 0;
    }
};
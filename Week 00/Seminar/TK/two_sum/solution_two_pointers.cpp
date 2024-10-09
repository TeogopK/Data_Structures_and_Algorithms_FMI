#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> sorted;

        for (int i = 0; i < nums.size(); i++)
        {
            pair<int, int> p(nums[i], i);
            sorted.push_back(p);
        }

        sort(sorted.begin(), sorted.end());

        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int currSum = sorted[left].first + sorted[right].first;
            if (currSum == target)
            {
                result.push_back(sorted[left].second);
                result.push_back(sorted[right].second);
                return result;
            }
            else if (currSum < target)
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return result;
    }
};
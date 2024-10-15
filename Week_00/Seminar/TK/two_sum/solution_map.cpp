#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> seen_nums;

        for (int i = 0; i < nums.size(); i++)
        {
            int friend_num = target - nums[i];

            if (seen_nums.find(friend_num) != seen_nums.end())
            {
                return {seen_nums[friend_num], i};
            }

            seen_nums[nums[i]] = i;
        }

        return {};
    }
};

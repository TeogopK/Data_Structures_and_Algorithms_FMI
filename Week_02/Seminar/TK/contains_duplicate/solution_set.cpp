#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};
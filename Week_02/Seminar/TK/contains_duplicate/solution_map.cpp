#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> m;
        for (int num : nums)
        {
            if (m.find(num) != m.end())
            {
                return true;
            }
            m[num] = 1;
        }
        return false;
    }
};

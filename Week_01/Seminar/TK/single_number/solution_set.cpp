#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> seen;

        for (int num : nums)
        {
            if (seen.count(num))
            {
                seen.erase(num);
            }
            else
            {
                seen.insert(num);
            }
        }

        return *seen.begin();
    }
};
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        vector<int> count(60001, 0);

        for (int num : nums)
        {
            count[num + 30000]++;
        }

        for (int i = 0; i < count.size(); ++i)
        {
            if (count[i] == 1)
            {
                return i - 30000;
            }
        }

        return 0;
    }
};

#include <vector>
#include <iostream>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int first_zero = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[first_zero] = nums[i];
                first_zero += 1;
            }
        }

        while (first_zero < nums.size())
        {
            nums[first_zero] = 0;
            first_zero += 1;
        }
    }
};
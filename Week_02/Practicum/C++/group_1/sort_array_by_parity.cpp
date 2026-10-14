// https://leetcode.com/problems/sort-array-by-parity/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            // Move left pointer to the right until an odd number is found
            while (left < right && nums[left] % 2 == 0)
            {
                left++;
            }

            // Move right pointer to the left until an even number is found
            while (left < right && nums[right] % 2 == 1)
            {
                right--;
            }

            // Swap the odd number at left with the even number at right
            if (left < n && right >= 0)
            {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        return nums;
    }
};
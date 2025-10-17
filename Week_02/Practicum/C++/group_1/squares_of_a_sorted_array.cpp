// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        // Two-pointer approach
        int left = 0;
        int right = n - 1;

        // Position to fill in result array, starting from the end
        int pos = n - 1;

        while (left <= right)
        {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq)
            {
                result[pos] = leftSq;
                left++;
            }
            else
            {
                result[pos] = rightSq;
                right--;
            }

            // Can be done in the result assignment step as well -> result[pos--] = ...
            pos--;
        }

        return result;
    }
};

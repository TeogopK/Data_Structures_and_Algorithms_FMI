class Solution
{
public:
    // O(n) time | O(1) space
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        for (auto &num : nums)
        {
            result ^= num;
        }

        return result;
    }
};
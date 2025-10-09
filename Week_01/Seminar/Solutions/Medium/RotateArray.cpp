class Solution
{

    void reverse(vector<int> &nums, int startIndex, int endIndex)
    {
        if (startIndex >= endIndex)
        {
            return;
        }
        for (int i = 0; i <= (endIndex - startIndex) / 2; i++)
        {
            std::swap(nums[startIndex + i], nums[endIndex - i]);
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int readIndex = 0;
        int writeIndex = 0;

        while (readIndex < nums.size())
        {
            if (nums[readIndex] != 0)
            {
                swap(nums[writeIndex], nums[readIndex]);
                writeIndex++;
            }

            readIndex++;
        }
    }
};
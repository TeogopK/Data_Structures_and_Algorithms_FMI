class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // Current subarray sum from start -> how many times can be achieved
        unordered_map<int, int> m; // try comparing with map (execution time will be higher)
        m[0] = 1;

        int totalCount = 0;
        int currentSum = 0;

        for (int el : nums)
        {
            currentSum += el;

            totalCount += m[currentSum - k];
            m[currentSum] += 1;
        }
        return totalCount;
    }
};
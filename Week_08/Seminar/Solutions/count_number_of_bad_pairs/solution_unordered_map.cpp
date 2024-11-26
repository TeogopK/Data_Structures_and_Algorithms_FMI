class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        long long N, allPairs, goodPairs;

        N = nums.size();
        allPairs = (N * (N - 1)) / 2;
        goodPairs = 0;

        unordered_map<int, long long> m;

        for (size_t i = 0; i < N; i++)
        {
            int target = nums[i] - i;

            if (m.count(target))
            {
                goodPairs += m[target];
            }
            m[target] += 1; // default is 0
        }

        return allPairs - goodPairs;
    }
};

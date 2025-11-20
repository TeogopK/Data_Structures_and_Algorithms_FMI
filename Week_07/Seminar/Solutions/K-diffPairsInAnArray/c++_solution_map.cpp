class Solution
{
public:
    int findPairs(std::vector<int>& nums, int k) {
        std::map<int, int> m;
        int count = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            m[nums[i]]++;
        }

        // Try using `auto`, or `for(auto it: m)*`
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (k == 0)
            {
                if (it->second > 1)
                {
                    count++;
                }
            }
            else
            {
                if (m.count(it->first + k))
                {
                    count++;
                }
            }
        }

        return count;
    }
};
class Solution
{
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, bool> first, seen;

        for (int num : nums)
        {
            if (seen[num - k])
            {
                first[num - k] = true;
            }
            if (seen[num + k])
            {
                first[num] = true;
            }

            seen[num] = true;
        }

        return first.size();
    }
};
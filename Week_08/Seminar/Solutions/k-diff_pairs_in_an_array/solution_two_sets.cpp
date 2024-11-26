using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_set<int> seen;
        set<pair<int, int>> results; // Can not use unordered_set with pair

        for (int el : nums)
        {
            if (seen.count(el - k))
            {
                results.insert({el - k, el});
            }
            if (seen.count(el + k))
            {
                results.insert({el, el + k});
            }
            seen.insert(el);
        }

        return results.size();
    }
};

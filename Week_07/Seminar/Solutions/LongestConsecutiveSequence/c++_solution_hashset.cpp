class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max_count = 0;

        for (int el : nums) {
            if (s.find(el - 1) != s.end()) {
                continue;
            }
            
            int current = el + 1;
            int total = 1;

            while (s.find(current) != s.end()) {
                // s.erase(current); --> improves the speed
                total++;
                current++;
            }
            
            max_count = max(total, max_count);
        }

        return max_count;
    }
};

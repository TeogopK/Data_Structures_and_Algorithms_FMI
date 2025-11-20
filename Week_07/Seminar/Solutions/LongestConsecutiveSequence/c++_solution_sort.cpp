class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int max_count = 1;
        int count = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }

            if (nums[i] + 1 == nums[i + 1]) {
                count++;
                max_count = max(count, max_count);
            }
            else {
                count = 1;
            }
        }

        return max_count;
    }
};

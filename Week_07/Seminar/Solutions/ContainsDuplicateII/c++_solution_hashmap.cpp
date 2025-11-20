class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeenAt;

        for (size_t i = 0; i < nums.size(); i++) {
            if (lastSeenAt.find(nums[i]) != lastSeenAt.end()) {
                if (i - lastSeenAt[nums[i]] <= k) {
                    return true;
                }
            }

            lastSeenAt[nums[i]] = i;
        }

        return false;
    }
};
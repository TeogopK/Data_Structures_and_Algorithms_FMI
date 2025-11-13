class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) != 0) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }

            m[nums[i]] = i;
        }

        return false;
    }
};
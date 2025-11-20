class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }

        unordered_set<int> s;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (s.find(nums[right]) != s.end()) {
                return true;
            }

            if (right >= k) {
                s.erase(nums[left]);
                left++;
            }

            s.insert(nums[right]);
        }

        return false;
    }
};

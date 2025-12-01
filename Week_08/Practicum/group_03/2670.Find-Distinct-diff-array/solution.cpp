class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        unordered_set<int> distincts;

        vector<int> pref(nums.size()), result(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            distincts.insert(nums[i]);
            pref[i] = distincts.size();
        }

        distincts.clear();

        result[nums.size() - 1] = pref[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; --i) {
            distincts.insert(nums[i + 1]);
            result[i] = pref[i] - distincts.size();
        }

        return result;
    }
};

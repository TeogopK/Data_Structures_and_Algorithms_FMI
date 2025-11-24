class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        vector<int> prefix(nums.size(), 0);
        prefix[0] = (nums[0] == 0 ? -1 : 1);
        for(int i = 1; i < nums.size(); ++i) {
            prefix[i] = prefix[i - 1] + (nums[i] == 0 ? -1 : 1);
        }

        unordered_map<int, int> mostLeftNum;
        unordered_map<int, int> mostRightNum;
        mostLeftNum[0] = 0;
        mostRightNum[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            mostLeftNum.emplace(prefix[i], i + 1);
            mostRightNum[prefix[i]] = i + 1;
        }

        int res = 0;

        for(pair<int, int> p : mostLeftNum) {
            if ((!mostRightNum.count(p.first)) || (mostRightNum[p.first] <= p.second)) {
                continue;
            }
            res = max(res, mostRightNum[p.first] - p.second);
        }
        return res;
    }
};

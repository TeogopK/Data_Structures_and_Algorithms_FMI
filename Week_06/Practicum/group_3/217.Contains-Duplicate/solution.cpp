class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int el : nums) {
            res ^= el;
        }
        return res;
    }
};

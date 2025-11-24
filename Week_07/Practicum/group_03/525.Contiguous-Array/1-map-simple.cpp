class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstPos;
        firstPos[0] = -1;

        int prefix = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 0 ? -1 : 1);

            if (firstPos.count(prefix)) {
                res = max(res, i - firstPos[prefix]);
            } else {
                firstPos[prefix] = i; 
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // key - sum
        // val - first occurence of that sum
        unordered_map<int, int> c;
        c[0] = -1; // sum was zero before the start of traversal
        int sum = 0;
        int maxLength = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            auto iter = c.find(sum);
            if(iter != c.end()) {
                maxLength = max(maxLength, i - iter->second);
            }
            else {
                c[sum] = i;
            }
        }
        return maxLength;
    }
};

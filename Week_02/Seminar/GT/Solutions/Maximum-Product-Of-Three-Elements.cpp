class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        size_t n = nums.size();
        int v1 = nums[0] * nums[1] * nums[n - 1];
        int v2 = nums[n - 3] * nums[n - 2] * nums[n - 1];
        return max(v1, v2);
    }
};

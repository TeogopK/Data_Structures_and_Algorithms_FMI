class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums);
        for (int i = nums.size() - 2; i >= 0; i--) {
            result[i] *= result[i + 1];
        }

        int product = nums[0];
        result[0] = result[1];
        for (size_t i = 1; i < nums.size() - 1; i++) {
            result[i] = product * result[i + 1];
            product *= nums[i];
        }
        result[nums.size() - 1] = product;

        return result;
    }
};
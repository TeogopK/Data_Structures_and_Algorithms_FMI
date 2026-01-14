class Solution {
public:
    void _permute(vector<int>& nums, vector<vector<int>>& result, int start) {
        if(start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(size_t i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            _permute(nums, result, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        _permute(nums, result, 0);
        
        return result;
    }
};

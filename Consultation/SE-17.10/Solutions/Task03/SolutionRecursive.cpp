class Solution {
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, size_t index, vector<int>& subset) {
        if(nums.size() == index) {
            result.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        rec(nums, index + 1, subset);
        
        subset.pop_back();
        rec(nums, index + 1, subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> v;
        backtrack(nums, 0, v);

        return result;
    }
};

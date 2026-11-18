// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
    vector<int> prep;
public:
    NumArray(vector<int>& nums) {
        prep.push_back(0);
        for(auto i: nums) {
            prep.push_back(i + prep[prep.size() - 1]);
        }
    }

    int sumRange(int left, int right) {
        return prep[right + 1] - prep[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

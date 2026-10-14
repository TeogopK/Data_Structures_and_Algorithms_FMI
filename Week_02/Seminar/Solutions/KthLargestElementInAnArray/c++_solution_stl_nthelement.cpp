class Solution {
public:
    // O(n) average time
    // https://en.cppreference.com/w/cpp/algorithm/nth_element.html
    int findKthLargest(vector<int>& nums, int k) {
        std::nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.end() - k);
    }
};
class Solution1 {
    void customReverse(vector<int>& nums, int startIndex, int endIndex) {
        if(startIndex >= endIndex) {
            return;
        }
        for(int i = 0; i <= (endIndex - startIndex) / 2; i++) {
            std::swap(nums[startIndex + i], nums[endIndex - i]);
        }
    }
public:
    // O(n) time | O(1) space
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        customReverse(nums, nums.size() - k, nums.size() - 1);
        customReverse(nums, 0, nums.size() - k - 1);
        customReverse(nums, 0, nums.size() - 1);
    }
};

class Solution2 {
public:
    // O(n) time | O(1) space
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.begin(), nums.end());
    }
};

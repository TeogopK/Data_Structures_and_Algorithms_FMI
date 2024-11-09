// Виж README.md за описание на решението.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        std::stack<int> min, max; // can be done without stacks, just two ints :D
        max.push(INT_MIN);
        min.push(INT_MAX);
        int n = nums.size(), min_idx = 0, max_idx = 0;

        for (int k = 0; k < n; ++k) {
            if (nums[k] < max.top()) {
                max_idx = k;
            } else {
                max.push(nums[k]);
            }

            if (nums[n - 1 - k] > min.top()) {
                min_idx = n - 1 - k;
            } else {
                min.push(nums[n - 1 - k]);
            }
        }

        return max_idx > min_idx ? max_idx - min_idx + 1 : 0;
    }
};
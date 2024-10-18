class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Sort the input array to bring duplicates together
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int target = size / 3;
        vector<int> result;

        for (int i = 0; i < size - target; i++) {
            // Check if the element occurs more than 'target' times
            if (nums[i] == nums[i + target]) {
                // Add the element to the result if it's not already added
                if (result.empty() || result.back() != nums[i]) {
                    result.push_back(nums[i]);
                }
                // Skip to the next element after the sequence
                i += target;
            }
        }

        return result;
    }
};

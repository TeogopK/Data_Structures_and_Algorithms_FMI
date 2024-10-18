class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 1;
        int size = nums.size();
        vector<int> result;

        for (int i = 1; i < size; i++) {
            if(nums[i] == nums[i-1])
                count++;
            else {
                if(count > size /3 )
                    result.push_back(nums[i-1]);
                count = 1;
            }
        }

        if (count > size / 3) {
            result.push_back(nums[size - 1]);
        }

        return result;
    }
};
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(size_t i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        double currentSum = sum;
        for(size_t i = k; i < nums.size(); i++) {
            currentSum = (currentSum - nums[i - k] + nums[i]);
            if(sum < currentSum) {
                sum = currentSum;
            }
        }
        
        return sum / k;
    }
};

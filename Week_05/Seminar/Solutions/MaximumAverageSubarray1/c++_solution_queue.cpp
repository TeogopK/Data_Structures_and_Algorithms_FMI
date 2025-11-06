class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        double sum = 0;
        for(size_t i = 0; i < k; i++) {
            q.push(nums[i]);
            sum += nums[i];
        }
        
        // find max sum and divide by k for the result
        double currentSum = sum;
        for(size_t i = k; i < nums.size(); i++) {
            currentSum = (currentSum - q.front() + nums[i]);
            q.pop();
            q.push(nums[i]);
            if(currentSum > sum) {
                sum = currentSum;
            }
        }
        
        return sum / k;
    }
};

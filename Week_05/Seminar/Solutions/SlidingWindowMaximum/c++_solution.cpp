class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // head - current max
        // next elements - potential max elements
        deque<int> dq;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            // keep the dq monotonic
            while(!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // pop the front if it is now outside the window!
            if(dq.front() <= i - k) {
                dq.pop_front();
            }

            // start working on the result after you have passed atleast one window (k elements) to the dq
            if(i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long result = 0;

        for(size_t _ = 0; _ < k; _++) {
            int current = pq.top();
            result += current;
            pq.pop();
            pq.push(ceil(current * 1.00 / 3));
        }
        
        return result;
    }
};

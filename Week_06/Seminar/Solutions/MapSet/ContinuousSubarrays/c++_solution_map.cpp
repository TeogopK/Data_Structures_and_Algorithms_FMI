class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        map<int, int> windowFreq;
        int l = 0, r = 0;

        while (r < nums.size()) {
            windowFreq[nums[r]]++;

            while (windowFreq.rbegin()->first - windowFreq.begin()->first > 2) {
                windowFreq[nums[l]]--;
                if (windowFreq[nums[l]] == 0) {
                    windowFreq.erase(nums[l]);
                }
                l++;
            }

            count += (r - l + 1);
            r++;
        }
        return count;
    }
};
class Solution {
public:
    int maxEl(vector<int>& nums) {
        int res = INT_MIN;
        for(int el : nums) {
            res = max(el, res);
        }
        return res;
    }

    int sum(vector<int>& nums) {
        int res = 0;
        for(int el : nums) {
            res += el;
        }
        return res;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = maxEl(nums);
        int r = sum(nums);

        int ans = -1;
        while (l <= r) {
            int mid = (r-l) / 2 + l;
            int curBox = 1;
            int curSum = 0;

            for(int el : nums) {
                if (curSum + el > mid) {
                    curBox++;
                    if (curBox > k) {
                        break;
                    }
                    curSum = el;
                } else {
                    curSum += el;
                }
            }
            if (curBox > k) {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};

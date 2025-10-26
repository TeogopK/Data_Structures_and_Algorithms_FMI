class Solution {
public:
    int maxArr(const vector<int>& arr) {
        int res = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            res = max(res, arr[i]);
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = maxArr(piles);
        int l = 1;
        int r = maxPile;
        int ans = maxPile;

        while(l <= r) {
            int mid = (r-l)/2 + l;

            long long curHours = 0; //can't overflow -> calculate entry!
            for(int i = 0; i < piles.size(); ++i) {
                curHours += piles[i] / mid + (piles[i] % mid != 0);
            }

            if (curHours > h) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

};

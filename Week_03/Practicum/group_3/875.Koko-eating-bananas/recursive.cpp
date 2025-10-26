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
        int max = maxArr(piles);
        return minBanana(piles, h, 1, max, max);
    }

    int minBanana(vector<int>& piles, int h, int l, int r, int min) {
        if (r < l) {
            return min;
        }
        int banPerHour = (r-l)/2 + l;
        long long totalNeededToEatAll = 0;
        for(int i = 0; i < piles.size(); ++i) {
            totalNeededToEatAll += piles[i] / banPerHour + !!(piles[i] % banPerHour);
        }
        if (totalNeededToEatAll > h) {
            return minBanana(piles, h, banPerHour + 1, r, min);
        } else {
            return minBanana(piles, h, l, banPerHour - 1, banPerHour);
        }
    }
};

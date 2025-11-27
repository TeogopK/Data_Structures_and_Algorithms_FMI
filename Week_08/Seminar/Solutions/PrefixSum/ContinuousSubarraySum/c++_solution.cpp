class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> leftoversSeen;
        leftoversSeen[0] = -1;

        int prefixLeftover = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixLeftover = (prefixLeftover + nums[i]) % k;

            auto earliestSeenAt = leftoversSeen.find(prefixLeftover);
            if (earliestSeenAt != leftoversSeen.end()) {
                if (i - (*earliestSeenAt).second > 1) {
                    return true;
                }
            }
            else {
                leftoversSeen[prefixLeftover] = i;
            }
        }

        return false;
    }
};
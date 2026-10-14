class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> counter(1001, 0);   // values are in [0, 1000]
        for (int x : nums1) {
            counter[x]++;
        }

        vector<int> result;
        for (int x : nums2) {
            if (counter[x] > 0) {
                result.push_back(x);
                counter[x]--;           // use up one copy
            }
        }
        return result;
    }
};

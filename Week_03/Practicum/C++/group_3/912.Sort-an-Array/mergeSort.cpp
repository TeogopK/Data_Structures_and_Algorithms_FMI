class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums;
        }

        int mid = nums.size() / 2;
        vector<int> lhs(nums.begin(), nums.begin() + mid);
        vector<int> rhs(nums.begin() + mid, nums.end());

        return merge(sortArray(lhs), sortArray(rhs));
    }


    vector<int> merge(vector<int>&& lhs, vector<int>&& rhs) {
        int size1 = lhs.size();
        int size2 = rhs.size();

        vector<int> res(size1 + size2, 0);
        int i = 0, j = 0, r = 0;

        while (i < size1 && j < size2) {
            if (lhs[i] < rhs[j]) {
                res[r++] = lhs[i++];
            } else {
                res[r++] = rhs[j++];
            }
        }

        while (i < size1) {
            res[r++] = lhs[i++];
        }

        while (j < size2) {
            res[r++] = rhs[j++];
        }

        return res;
    }
};

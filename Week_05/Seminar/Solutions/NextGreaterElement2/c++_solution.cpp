class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(curr);
        }
        return nge;
    }
};

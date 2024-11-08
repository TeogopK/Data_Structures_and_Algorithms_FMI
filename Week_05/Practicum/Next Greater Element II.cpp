class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        std::stack<std::pair<int, int>> stack;
        std::vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            while (!stack.empty() && stack.top().first < nums[i]) {
                ans[stack.top().second] = nums[i];
                stack.pop();
            }

            stack.emplace(nums[i], i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            while (!stack.empty() && stack.top().first < nums[i]) {
                ans[stack.top().second] = nums[i];
                stack.pop();
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return res;
    }
};

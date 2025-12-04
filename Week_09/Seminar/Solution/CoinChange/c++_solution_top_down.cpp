class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, INT_MIN);
        return dfs(coins, amount, memo);
    }

    // Recursive function to find minimum coins needed
    int dfs(vector<int>& coins, int rem, vector<int>& memo) {
        if (rem == 0) {
            return 0;
        }
        if (rem < 0)  {
            return -1;
        }
        if (memo[rem] != INT_MIN) {
            return memo[rem];
        }

        int res = INT_MAX;
        for (int coin : coins) {
            int subRes = dfs(coins, rem - coin, memo);
            if (subRes >= 0 && subRes < res) {
                res = subRes + 1;
            }
        }
        
        return memo[rem] = (res == INT_MAX) ? -1 : res;
    }
};

// The task is to minimize the maximum cost incurred when guessing a number in the range [1, n].
// You pay the value of the guessed number if it's wrong. The challenge is to decide which numbers to guess
// to minimize the worst-case cost.

class Solution {
public:
    // Calculate the minimum cost to guarantee a win in the range [minValue, maxValue].
    int guess(vector<vector<int>>& table, int minValue, int maxValue) {
        // Base case: If the range has one or no numbers, there is no cost because no guessing is required.
        if (minValue >= maxValue)
            return 0;

        // If the result for this range is not already calculated, compute it.
        if (table[minValue][maxValue] == 0) {
            // Initialize the answer to a very large value to find the minimum cost.
            int ans = INT_MAX, cost;
            // Iterate through all possible numbers `i` in the range [minValue, maxValue].
            for (int i = minValue; i <= maxValue; i++) {
                // The cost of choosing `i` is the value of `i` plus the maximum cost
                // of the two resulting ranges: [minValue, i-1] and [i+1, maxValue].
                cost = i + max(guess(table, minValue, i - 1), guess(table, i + 1, maxValue));
                // Update the answer to the minimum cost found so far.
                ans = min(ans, cost);
            }
            // Store the computed result in the table for future use (memoization).
            table[minValue][maxValue] = ans;
        }

        // Return the result for the current range.
        return table[minValue][maxValue];
    }

    int getMoneyAmount(int n) {
        // Create a memoization table of size (n+1) x (n+1) initialized to 0.
        // The table stores the minimum cost for each range [minValue, maxValue].
        vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));

        // Call the helper function to calculate the result for the full range [1, n].
        return guess(table, 1, n);
    }
};

/*
Example Flow:

Input: n = 4

1. Start with range [1, 4]. Try guessing each number `i` (1 to 4):
   - If `i = 1`: Cost = 1 + max(cost of [2, 4]) = 1 + cost of [2, 4]
   - If `i = 2`: Cost = 2 + max(cost of [1, 1], cost of [3, 4])
   - If `i = 3`: Cost = 3 + max(cost of [1, 2], cost of [4, 4])
   - If `i = 4`: Cost = 4 + max(cost of [1, 3]) = 4 + cost of [1, 3]

2. For each subrange (e.g., [2, 4], [1, 3]), recursively calculate the cost.

3. Use memoization to store results for ranges like [2, 4] and [1, 3] to avoid redundant computation.

4. Finally, find the minimum cost among all guesses for range [1, 4].

Output: 4
The minimum cost to guarantee a win is 4.
*/

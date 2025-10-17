class Solution {
public:
    // Time: O(2^N) | Space: O(N)
    // Note: We can say that time complexity is O(N * 2^N) because of the push_back to the result
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;

        int upperBound = pow(2, n + 1);
        // generate bitmask, from 0..00 to 1..11
        for (int i = pow(2, n); i < upperBound; i++) {
            string bitmask = bitset<32>(i).to_string().substr(32 - n);
            
            // append subset corresponding to that bitmask
            vector<int> curr;
            for (int j = 0; j < n; ++j) {
                if (bitmask.at(j) == '1') {
                    curr.push_back(nums[j]);
                }
            }
            
            output.push_back(curr);
        }
        
        return output;
    }
};

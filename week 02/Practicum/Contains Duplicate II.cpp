class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Create a vector of pairs to store the numbers along with original indexes
        vector<pair<int, int>> sortedNums;

        // Fill the vector with pairs (number, index)
        for(int i = 0; i < nums.size(); i++) {
            sortedNums.push_back({nums[i], i});
        }

        // Sort the vector based on the numbers (the first element of each pair)
        sort(sortedNums.begin(), sortedNums.end());

        for(int i = 0; i < nums.size() - 1; i++) {
            // Check if the current number is the same as the next number and 
            // if the difference between their original indices is <= k
            if (sortedNums[i].first == sortedNums[i+1].first && abs(sortedNums[i].second - sortedNums[i+1].second) <= k) {
                return true;
            }
        }
        
        // If no nearby duplicate is found, return false
        return false;
    }
};
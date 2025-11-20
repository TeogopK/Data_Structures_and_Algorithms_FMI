class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> leftNumbers;

        for (auto n : nums) {
            leftNumbers.insert(n);
        }

        int maxLength = 0;
        while (!leftNumbers.empty()) {
            int innerLength = 1;
            int low = *leftNumbers.begin();
            int high = low;
            // needed for O(1), otherwise you will traverse the same seq twice
            leftNumbers.erase(low);
            while (leftNumbers.find(low - 1) != leftNumbers.end()) {
                low = low - 1;
                innerLength += 1;
                leftNumbers.erase(low);
            }
            while (leftNumbers.find(high + 1) != leftNumbers.end()) {
                high = high + 1;
                innerLength += 1;
                leftNumbers.erase(high);
            }
            maxLength = max(maxLength, innerLength);
        }

        return maxLength;
    }
};
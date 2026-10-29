// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    // O(n) time | O(1) space
    int maxArea(vector<int>& heights) {
        int leftIdx = 0;
        int rightIdx = heights.size() - 1;
        int result = INT_MIN;

        while(leftIdx < rightIdx) {
            int curr = min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);
            result = max(result, curr);
            
            if(heights[leftIdx] < heights[rightIdx]) {
                leftIdx++;
            }
            else {
                rightIdx--;
            }
        }

        return result;
    }
};

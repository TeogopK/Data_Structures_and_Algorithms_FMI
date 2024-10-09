class Solution {
public:
    int maxArea(vector<int>& heights) {
        int leftIdx = 0;
        int rightIdx = heights.size() - 1;
        int max = std::min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);

        while(leftIdx < rightIdx) {
            int currentMax = std::min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);
            
            max = std::max(max, currentMax);
            if(heights[leftIdx] > heights[rightIdx]) {
                rightIdx--;
            }
            else {
                leftIdx++;
            }
        }
        return max;
    }
};
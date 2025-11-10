#define NumPos pair<int, int>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;

        stack<NumPos> columns;
        int curLen = 1;
        columns.push({0, 0});

        for(int i = 0; i < heights.size(); ++i) {
            while(columns.top().first >= heights[i]) {
                NumPos& popped = columns.top();
                columns.pop();
                if (popped.first == heights[i]) {
                    break;
                }

                int width = i - columns.top().second;
                int height = popped.first;
                ans = max(ans, width * height);
            }
            columns.push({heights[i], i + 1});
        }

        while(columns.top().first > 0) {
            NumPos& popped = columns.top();
            columns.pop();

            int width = heights.size() - columns.top().second;
            int height = popped.first;
            ans = max(ans, width * height);
        }
        return ans;
    }
};

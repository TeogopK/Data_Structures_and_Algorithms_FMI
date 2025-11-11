// Version 1 - two stacks - for the smaller on left and smaller on right
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> st;

        // Find the index of the next smaller element on the left for each bar
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack to reuse it for finding the next smaller element on the right
        while (!st.empty())
        {
            st.pop();
        }

        // Find the index of the next smaller element on the right for each bar
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            rightSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        // Calculate the maximum area for each bar using the indices of smaller bars
        for (int i = 0; i < n; i++)
        {
            int width = rightSmaller[i] - leftSmaller[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Version 2 - one stack - pop when we find a smaller height
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        stack<pair<int, int>> st;
        int n = heights.size();

        for (int i = 0; i < n; i++)
        {
            int start = i;

            // While the current height is less than the height of the bar at the top of the stack,
            // we pop from the stack and calculate the area of the rectangle that can be formed.
            // If the top is taller, it means we can form a rectangle with that height extending
            // from its index to the current index.
            while (!st.empty() && st.top().second > heights[i])
            {
                auto [index, h] = st.top();
                st.pop();
                res = max(res, h * (i - index));

                start = index;
            }

            st.push({start, heights[i]});
        }

        // If still in the stack, that means these bars can extend to the end of the histogram.
        // We pop them and calculate the area accordingly.
        while (!st.empty())
        {
            auto [index, h] = st.top();
            st.pop();
            res = max(res, h * (n - index));
        }

        return res;
    }
};

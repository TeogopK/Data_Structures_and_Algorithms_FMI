#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int maxWater = 0;
    int left = 0, right = n - 1;

    while (left < right)
    {
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int water = height * width;
        maxWater = max(maxWater, water);

        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << maxWater;

    return 0;
}

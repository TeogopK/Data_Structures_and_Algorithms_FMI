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

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int height = min(heights[i], heights[j]);
            int width = j - i;
            int water = height * width;
            maxWater = max(maxWater, water);
        }
    }

    cout << maxWater;

    return 0;
}

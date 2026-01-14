#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> binarySearch(vector<int>& nums, int target)
{

    int iterations = 0;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        iterations++;

        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return { mid, iterations };
        }

        else if (nums[mid] > target)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }

    }

    return { -1, iterations };
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int k;
    cin >> k;
    vector<int> targets(k);
    for (int i = 0; i < k; i++)
    {
        cin >> targets[i];
    }

    vector<pair<int, int>> res(k);
    for (int i = 0; i < k; i++)
    {
        res[i] = binarySearch(nums, targets[i]);
    }

    for (int i = 0; i < k; i++)
    {
        cout << res[i].first << " ";
    }

    cout << endl;

    for (int i = 0; i < k; i++)
    {
        cout << res[i].second << " ";
    }

    return 0;
}

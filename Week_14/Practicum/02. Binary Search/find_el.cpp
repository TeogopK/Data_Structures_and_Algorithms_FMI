#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int target;
        cin >> target;

        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == right)
        {
            cout << distance(nums.begin(), left) << endl;
        }

        else
        {
            cout << distance(nums.begin(), left) << " " << distance(nums.begin(), right) - 1 << endl;
        }
    }

    return 0;
}

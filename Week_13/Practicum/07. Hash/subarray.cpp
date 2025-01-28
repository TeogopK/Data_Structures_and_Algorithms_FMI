#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_set<int> s;
    int maxSize = 0;
    int leftMost = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.count(nums[i]))
        {
            while (!s.empty() && s.count(nums[i]))
            {
                s.erase(nums[leftMost++]);
            }
        }

        s.insert(nums[i]);
        maxSize = max(maxSize, (int)s.size());
    }

    cout << maxSize;

    return 0;
}

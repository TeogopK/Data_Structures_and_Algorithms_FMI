#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long>& cookers, long long n, long long m)
{
    long long res = 0;
    for (long long i = 0; i < cookers.size(); i++)
    {
        res += m / cookers[i];
    }

    return res >= n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<long long> cookers(k);
    long long maxTime = LLONG_MIN;

    for (long long i = 0; i < k; i++)
    {
        cin >> cookers[i];
        maxTime = max(maxTime, cookers[i]);
    }

    long long l = 0;
    long long r = maxTime * n;

    long long ans = 0;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;

        if (check(cookers, n, m))
        {
            ans = m;
            r = m - 1;
        }

        else
        {
            l = m + 1;
        }
    }

    cout << ans;

    return 0;
}
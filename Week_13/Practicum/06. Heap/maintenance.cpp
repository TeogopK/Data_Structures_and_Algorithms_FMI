#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, t, b, n, num;
    cin >> k >> t >> b >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        pq.push(num);

        int count = k;
        if (i % t == 0 && b)
        {
            while (count--)
            {
                cout << pq.top() << " ";
                pq.pop();
            }

            b--;
        }
    }

    while (b--)
    {
        int count = k;
        while (pq.size() && count--)
        {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

    return 0;
}

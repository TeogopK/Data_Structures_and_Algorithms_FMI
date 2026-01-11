#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> seen;
    queue<int> q;

    size_t count;
    cin >> count;

    for (size_t i = 0; i < count; ++i) {
        int val;
        cin >> val;

        seen[val]++;

        if (seen[val] == 1) {
            q.push(val);
        }

        while (!q.empty() && seen[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << -1 << " ";
        }
        else {
            cout << q.front() << " ";
        }
    }
}

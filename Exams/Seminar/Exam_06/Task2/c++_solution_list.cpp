#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> seen;
    list<int> lst;

    size_t count;
    cin >> count;

    for (size_t i = 0; i < count; ++i) {
        int val;
        cin >> val;

        seen[val]++;

        if (seen[val] == 1) {
            lst.push_front(val);
        }

        while (!lst.empty() && seen[lst.back()] > 1) {
            lst.pop_back();
        }

        if (lst.empty()) {
            cout << -1 << " ";
        }
        else {
            cout << lst.back() << " ";
        }
    }
}

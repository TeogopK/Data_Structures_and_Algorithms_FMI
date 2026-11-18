#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> times;
set<int>possibleRoots;
int t = 0;
void dfs(int currentNode, vector<vector<int>>& tree) {
    t++;
    times[currentNode].first = t;
    for (const auto& neighbour : tree[currentNode]) {
        dfs(neighbour, tree);
    }
    t++;
    times[currentNode].second = t;
}

bool isAncestor(int a, int b) {
    return times[a].first < times[b].first&& times[a].second > times[b].second;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> tree(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        possibleRoots.insert(a);
        possibleRoots.erase(b);
    }

    int root = *possibleRoots.begin();
    dfs(root, tree);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (isAncestor(a, b)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

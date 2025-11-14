#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

vector<int> children[MAXN];
int entry[MAXN], exit_[MAXN];
int timer = 0;

void dfs(int u) {
    entry[u] = ++timer;
    for (int v : children[u]) {
        dfs(v);
    }
    exit_[u] = ++timer;
}

bool isDescendant(int anc, int desc) {
    return entry[anc] <= entry[desc] && exit_[anc] >= exit_[desc];
}

int main() {
    int n;
    cin >> n;

    // Четене на дървото (root няма родител)
    // Ако стойностите са равни на индексите (1, 2, 3, ... n)
    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;         // parent е индекс, напр. 1, 2, ...
        children[parent].push_back(i);
    }

    // DFS от root (приемаме, че root е 1)
    dfs(1);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        // За заявки "x наследник ли е на y"
        cout << (isDescendant(y, x) ? "Yes\n" : "No\n");
    }
    return 0;
}
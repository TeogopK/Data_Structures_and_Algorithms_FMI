#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;

vector<pair<int, int>> graph[MAXN];

vector<int>parent(MAXN, -1);
vector<int>dist(MAXN, INT_MAX);

int main() {

    int n, m, s, x;
    cin >> n >> m >> s >> x;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>>pq;
    pq.push({ 0, s });
    dist[s] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int currentNode = top.second;
        int currentWeight = top.first;

        if (currentWeight > dist[currentNode]) continue;

        for (const auto& neighbour : graph[currentNode]) {
            int newNode = neighbour.first;
            int newWeight = neighbour.second;

            if (currentWeight + newWeight < dist[newNode]) {
                pq.push({ currentWeight + newWeight, newNode });
                dist[newNode] = currentWeight + newWeight;
                parent[newNode] = currentNode;
            }
        }
    }

    vector<int>path;
    while (parent[x] != -1) {
        path.push_back(x);
        x = parent[x];
    }
    path.push_back(x);

    reverse(path.begin(), path.end());

    if (path.size() == 1) {
        cout << -1;
    }
    else {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    }

    return 0;
}

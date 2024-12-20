#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // graph[u] = vector of pairs (v, weight)
    vector<vector<pair<int, long long>>> graph(n, vector<pair<int, long long>>());
    
    for(int i = 0; i < m; ++i){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int k;
    cin >> k;
    vector<int> T(k);
    for(auto &x : T) cin >> x;
    
    // Initialize distance array
    vector<long long> dist(n, INF);
    
    // Priority queue: min-heap based on distance
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;
    
    // Initialize T nodes with distance 0
    for(auto t : T){
        dist[t] = 0;
        pq.push({0, t});
    }
    
    // Dijkstra's algorithm
    while(!pq.empty()){
        auto [current_dist, u] = pq.top(); 
        pq.pop();
        if(current_dist > dist[u]) 
            continue;
        for(auto &[v, w] : graph[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        int query;
        cin >> query;
        // If the vertex is in T, distance is 0
        cout << dist[query] << "\n";
    }
    
    return 0;
}

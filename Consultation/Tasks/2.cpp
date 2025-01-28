#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    long long weight;
    
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }
};

int myFind(int x, vector<int>& parent)
{
    if(x == parent[x])
        return x;
    
    return parent[x] = myFind(parent[x], parent);
}

bool myUnion(int x, int y, vector<int>& parent, vector<int>& depth, vector<long long>& weights, long long weight)
{
    int p1 = myFind(x, parent);
    int p2 = myFind(y, parent);
    if(p1 == p2)
    {
        return false;
    }
    
    if(depth[p1] > depth[p2])
    {
        swap(p1, p2);
    }
    else if(depth[p1] == depth[p2])
    {
        depth[p2]++;
    }
    
    parent[p1] = p2;
    weights[p2] += weights[p1] + weight;
    
    return true;
}

void solve()
{
    int v, e, k;
    cin >> v >> e >> k;
    
    vector<Edge> edges(e);
    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }
    
    vector<int> depth(v, 0);    
    vector<int> parent(v);
    vector<long long> weights(v, 0);
    for(int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    
    sort(edges.begin(), edges.end());
    
    for(auto edge: edges)
    {
        myUnion(edge.from, edge.to, parent, depth, weights, edge.weight);
    }
    
    unordered_map<int, int> counts;
    for(int i = 0; i < v; i++)
    {
        int label = myFind(i, parent);
        counts[label]++;
    }
    
    long long result = 0;
    for(auto& kvp : counts)
    {
        int label = kvp.first;
        int count = kvp.second;
        if(count % k == 0)
        {
            result += weights[label];
        }
    }
    
    cout << result << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
}
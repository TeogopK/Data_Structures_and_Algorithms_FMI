#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int from, to;
    long long weight;
};

int main() {
    int nodesCount, edgesCount, start, end;
    std::cin >> nodesCount >> edgesCount >> start >> end;
    vector<Edge> edgeList;
    for(int i = 0; i < edgesCount; i++) {
        int from, to;
        long long weight;
        cin >> from >> to >> weight;
        edgeList.push_back({ from, to, weight });
    }
    
    vector<long long> distances(nodesCount + 1, LLONG_MIN);
    distances[start] = 0;
    for(int i = 0; i < nodesCount; i++) {
        for(int i = 0; i < edgesCount; i++) {
            auto& edge = edgeList[i];
            distances[edge.to] = max(distances[edge.to], distances[edge.from] + edge.weight);
        }
    }
    
    if(distances[end] == LLONG_MIN) {
        cout << -1;
    }
    else {
        cout << distances[end];
    }
}

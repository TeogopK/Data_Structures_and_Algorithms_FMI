#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight; // Sort in descending order
    }
};

class UnionFind {
private:
    std::vector<size_t> parentsContainer;
    std::vector<size_t> sizes;

    size_t componentsCount;

public:
    UnionFind(size_t vertices);

    size_t getParent(size_t vertex);
    bool areInOneSet(size_t first, size_t second);
    void unionVertices(size_t first, size_t second);
    size_t getComponentsCount() const;
};

UnionFind::UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices), componentsCount(vertices) {
    for (size_t i = 0; i < vertices; i++) {
        parentsContainer[i] = i;
        sizes[i] = 1;
    }
}

bool UnionFind::areInOneSet(size_t first, size_t second) {
    return getParent(first) == getParent(second);
}

size_t UnionFind::getParent(size_t vertex) {
    if (parentsContainer[vertex] == vertex) {
        return vertex;
    }

    return parentsContainer[vertex] = getParent(parentsContainer[vertex]);
}

void UnionFind::unionVertices(size_t first, size_t second) {
    size_t parentOfFirst = getParent(first);
    size_t parentOfSecond = getParent(second);

    if (parentOfFirst == parentOfSecond) {
        return;
    }

    if (sizes[parentOfFirst] < sizes[parentOfSecond]) {
        std::swap(parentOfFirst, parentOfSecond);
    }
    // second will have lower size
    parentsContainer[parentOfSecond] = parentOfFirst;
    sizes[parentOfFirst] += sizes[parentOfSecond];
    componentsCount--;
}

size_t UnionFind::getComponentsCount() const {
    return componentsCount;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    vector<Edge> selected;

    for (const auto& edge : edges) {
        // If you are checking components count after uniting you will
        // skip the edge case where K is equal to N
        if (uf.getComponentsCount() == K) {
            break;
        }

        if (uf.areInOneSet(edge.u, edge.v)) {
            continue;
        }

        uf.unionVertices(edge.u, edge.v);
        selected.push_back(edge);
    }

    vector<long long> componentSum(N, 0);

    for (const auto& edge : selected) {
        int root = uf.getParent(edge.u);
        componentSum[root] += edge.weight;
    }

    vector<long long> result;
    vector<bool> visited(N, false);

    for (int i = 0; i < N; i++) {
        int root = uf.getParent(i);
        if (!visited[root]) {
            visited[root] = true;
            result.push_back(componentSum[root]);
        }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
}

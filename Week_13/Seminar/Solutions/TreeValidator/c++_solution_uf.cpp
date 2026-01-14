#include <bits/stdc++.h>
using namespace std;
#include <vector>

class UnionFind {
private:
    std::vector<size_t> parentsContainer;
    std::vector<size_t> sizes;

    // extend the union find with counter
    size_t unionsCount;
    size_t getParent(size_t vertex);
public:
    UnionFind(size_t vertices);
    size_t getUnionsCount() const;
    bool areInOneSet(size_t first, size_t second);
    void unionVertices(size_t first, size_t second);
};

UnionFind::UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices), unionsCount(vertices) {
    for (size_t i = 0; i < vertices; i++) {
        parentsContainer[i] = i;
        sizes[i] = 1;
    }
}

size_t UnionFind::getUnionsCount() const {
    return unionsCount;
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

    if(parentOfFirst == parentOfSecond) {
        return;
    }
    
    if (sizes[parentOfFirst] < sizes[parentOfSecond]) {
        std::swap(parentOfFirst, parentOfSecond);
    }
    // second will have lower size
    parentsContainer[parentOfSecond] = parentOfFirst;
    sizes[parentOfFirst] += sizes[parentOfSecond];
    unionsCount--;
}

struct Edge{
    int from;
    int to;
};

int main() {
    int q;
    std::cin >> q;
    
    for(size_t i = 0; i < q; i++) {
        int v, e;
        cin >> v >> e;
        
        vector<Edge> edges(e);
        for(size_t i = 0; i < e; i++) {
            int from, to;
            cin >> from >> to;
            edges[i] = { from, to };
        }
        
        UnionFind uf(v);
        bool result = true;
        for(auto& edge: edges) {
            if(uf.areInOneSet(edge.from, edge.to)) {
                result = false;
                break;
            }
            uf.unionVertices(edge.from, edge.to);
        }
        
        bool areAllMerged = uf.getUnionsCount() == 1;
        std::cout << (result && areAllMerged) << endl;
        
        
    }
}

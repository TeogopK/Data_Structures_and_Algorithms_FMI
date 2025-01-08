class UnionFind {
private:
    std::vector<size_t> parentsContainer;
    std::vector<size_t> sizes;

    size_t getParent(size_t vertex);
public:
    UnionFind(size_t vertices);

    bool areInOneSet(size_t first, size_t second);
    void unionVertices(size_t first, size_t second);
};
UnionFind::UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices, 1) {
    for (size_t i = 0; i < vertices; i++) {
        parentsContainer[i] = i;
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

    if(parentOfFirst == parentOfSecond) {
        return;
    }
    
    if (sizes[parentOfFirst] < sizes[parentOfSecond]) {
        std::swap(parentOfFirst, parentOfSecond);
    }
    // second will have lower size
    parentsContainer[parentOfSecond] = parentOfFirst;
    sizes[parentOfFirst] += sizes[parentOfSecond];
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodesCount = isConnected.size();
        UnionFind uf(nodesCount);
        int numberOfComponents = nodesCount;
        for(size_t i = 0; i < nodesCount; i++) {
            for(size_t j = 0; j < nodesCount; j++) {
                if(isConnected[i][j] && !uf.areInOneSet(i, j)) {
                    uf.unionVertices(i, j);
                    numberOfComponents--;
                    if(numberOfComponents == 1) {
                        break;
                    }
                }
            }
        }

        return numberOfComponents;
    }
};

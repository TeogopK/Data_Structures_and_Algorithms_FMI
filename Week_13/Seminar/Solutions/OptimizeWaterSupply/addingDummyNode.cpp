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
UnionFind::UnionFind(size_t vertices) : parentsContainer(vertices), sizes(vertices) {
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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
      // add edges from dummy node
        for(int i = 1; i <= n; i++) {
            pipes.push_back({0, i, wells[i - 1]});
        }

        UnionFind ufi(n + 1);
        std::sort(pipes.begin(), pipes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        });
        int components = n + 1;
        int result = 0;
        for(size_t i = 0; i < pipes.size(); i++) {
            if(ufi.areInOneSet(pipes[i][0], pipes[i][1])) {
                continue;
            }

            ufi.unionVertices(pipes[i][0], pipes[i][1]);
            result += pipes[i][2];
            components--;
            if(components == 1) {
                break;
            }
        }

        return result;
    }
};

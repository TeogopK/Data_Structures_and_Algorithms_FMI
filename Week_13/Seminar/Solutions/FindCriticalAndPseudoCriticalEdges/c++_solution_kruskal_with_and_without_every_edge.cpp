
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // add index to every edge, because we will sort them by weight...
        for(size_t i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        // result[0] => critical[]
        // result[1] => pseudo[]
        vector<vector<int>> result(2, vector<int>());

        sort(edges.begin(), edges.end(), [](const vector<int>& l, const vector<int>& r){
            return l[2] < r[2];
        });

        UnionFind uf(n);
        int mstWeight = 0;
        int components = n;
        for(auto& edge: edges) {
            if(uf.areInOneSet(edge[0], edge[1])) {
                continue;
            }

            mstWeight += edge[2];
            uf.unionVertices(edge[0], edge[1]);
            components--;
            if(components == 1) {
                break;
            } 
        }

        // try what will happen if each edge is removed
        for(size_t i = 0; i < edges.size(); i++) {
            UnionFind ufWithoutEdge(n);
            int mstWeightWithoutEdge = 0;
            int components = n;
            for(size_t j = 0; j < edges.size(); j++) {
                if(i == j || ufWithoutEdge.areInOneSet(edges[j][0], edges[j][1])) {
                    continue;
                }

                mstWeightWithoutEdge += edges[j][2];
                ufWithoutEdge.unionVertices(edges[j][0], edges[j][1]);
                components--;
                if(components == 1) {
                    break;
                }
            }

            // if the weight is changed => critical
            // if the edge disconnected the graph => critical
            if(mstWeightWithoutEdge > mstWeight || components > 1) {
                result[0].push_back(edges[i][3]); // pushback index
            }
            else {
                // the edge might be pseudo or not relevant at all
                UnionFind ufWithEdge(n);
                ufWithEdge.unionVertices(edges[i][0], edges[i][1]);
                int mstWeightWithEdge = edges[i][2];
                int components = n;
                for(size_t j = 0; j < edges.size(); j++) {
                    if(i == j || ufWithEdge.areInOneSet(edges[j][0], edges[j][1])) {
                        continue;
                    }

                    mstWeightWithEdge += edges[j][2];
                    ufWithEdge.unionVertices(edges[j][0], edges[j][1]);
                    components--;
                    if(components == 1) {
                        break;
                    }
                }
  
                // If the weight is the same => this edge is part of atleast one mst
                if (mstWeightWithEdge == mstWeight) {
                    result[1].push_back(edges[i][3]);
                }
            }
        }


        return result;
    }
};

#include <vector>

class UnionFind {
private:
    std::vector<size_t> parentsContainer;
    std::vector<size_t> sizes;

    size_t componentsCount;

    size_t getParent(size_t vertex);
public:
    UnionFind(size_t vertices);

    bool areInOneSet(size_t first, size_t second);
    void unionVertices(size_t first, size_t second);
    size_t getComponentsCount() const;
};

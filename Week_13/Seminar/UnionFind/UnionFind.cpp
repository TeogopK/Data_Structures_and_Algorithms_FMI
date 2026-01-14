#include "UnionFind.h"

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
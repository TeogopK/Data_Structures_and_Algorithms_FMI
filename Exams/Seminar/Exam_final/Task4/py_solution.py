from collections import defaultdict


def find(x, parents):
    if parents[x] == x:
        return x

    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent


def union(x, y, parents, rank):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if rank[x_root] < rank[y_root]:
        parents[x_root] = y_root
    elif rank[x_root] > rank[y_root]:
        parents[y_root] = x_root
    else:
        parents[x_root] = y_root
        rank[y_root] += 1


def kruskal(V, edges, K):
    """
    Modified to find the maximum via sorting.
    Also important is to do a forest not a tree.
    We do that by stopping when we have placed not V - 1 edges to connect all V vertgices,
    but rather V - 2 to have 2 components, V - 3 for 3, to V - K for K components.

    After that we do a postprocessing to get the sum of each component.
    """
    edges.sort(key=lambda x: -x[2])  # Max Spanning Tree
    parents = [i for i in range(V + 1)]
    rank = [0] * (V + 1)

    chosen_edges_indexes = []

    for i, (x, y, w) in enumerate(edges):
        if len(chosen_edges_indexes) == V - K:

            break

        if find(x, parents) != find(y, parents):
            chosen_edges_indexes.append(i)
            union(x, y, parents, rank)

    sums_of_components = get_sums_of_components(chosen_edges_indexes, edges, parents, V)
    return sums_of_components


def get_sums_of_components(chosen_edges_indexes, edges, parents, V):
    """
    We have each connected component represented by a single parent.
    We sum the weights of each edge used in each component.
    The used edges are saved in a list of indexes - chosen_edges_indexes.
    """
    comp_sum = defaultdict(int)

    for idx in chosen_edges_indexes:
        x, y, w = edges[idx]
        root = find(x, parents)
        comp_sum[root] += w

    for i in range(V):
        """For the components with only one vertex - we have no edges, so the sum is 0."""
        root = find(i, parents)
        comp_sum[root] += 0

    return sorted(comp_sum.values())


V, E, K = map(int, input().split())
graph_list_of_edges = [tuple(map(int, input().split())) for _ in range(E)]

answer = kruskal(V, graph_list_of_edges, K)
print(*answer)

"""
Solution idea:
    Modify the Kruskal's algorithm to count
        the nodes in each minimal tree.
    Save the weight of each minimal tree in the root of the tree. 
"""
def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    parents[y_root] = x_root

def kruskal(V, K, edges):
    edges.sort(key=lambda x: x[2])
    parents = [i for i in range(V)]

    edges_count = [1] * V
    weights = [0] * V

    for x, y, w in edges:
        x_root = find(x, parents)
        y_root = find(y, parents)
        
        if  x_root != y_root:
            edges_count[x_root] += edges_count[y_root]
            
            weights[x_root] += weights[y_root] + w
            weights[y_root] = 0
            
            union(x, y, parents)
            
    total = 0
    for count, weight in zip(edges_count, weights):
        if count % K == 0:
            total += weight

    return total


T = int(input())

for _ in range(T):
    V, E, K = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(E)]

    output = kruskal(V, K, edges)
    print(output)

def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents):
    x_root = find(x, parents)
    y_root = find(y, parents)

    if x_root != y_root:
        parents[x_root] = y_root
        return 1
        
    return 0

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        parents = [i for i in range(n)]
        for edge in edges:
            union(edge[0], edge[1], parents)

        return find(source, parents) == find(destination, parents)
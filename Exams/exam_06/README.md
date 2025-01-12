def find(x, parents):
    if parents[x] == x:
        return x
    
    furthest_parent = find(parents[x], parents)
    parents[x] = furthest_parent

    return furthest_parent

def union(x, y, parents, sizes):
    x_root = find(x, parents)
    y_root = find(y, parents)

    # Increment the size every time
    if sizes[x_root] < sizes[y_root]:
        parents[x_root] = y_root
        sizes[y_root] += sizes[x_root]
    elif sizes[x_root] > sizes[y_root]:
        parents[y_root] = x_root
        sizes[x_root] += sizes[y_root]
    else:
        parents[x_root] = y_root
        sizes[y_root] += sizes[x_root]

def solve(graph, initial):
        n = len(graph)
        m = len(initial)

        parents = [v for v in range(n)]
        sizes = [1] * n

        infected = set(initial)
        healthy = set(v for v in range(n) if v not in infected)
        
        # Build only the safe ones
        for i in healthy:
            for j in healthy:
                if j not in graph[i]:
                    continue
                if find(i, parents) != find(j, parents):
                    union(i, j, parents, sizes)

        group_infectors = {v: set() for v in healthy}
        for v in infected:
            for w in healthy:
                if w not in graph[v]:
                    continue
                parent_w = find(w, parents)
                group_infectors[parent_w].add(v)

        saved = {v: 0 for v in infected}
        for v in infected:
            for w in healthy:
                parent_w = find(w, parents)
                if len(group_infectors[parent_w]) == 1 and v in group_infectors[parent_w]:
                    saved[v] += sizes[parent_w]
                    group_infectors[parent_w] = set()

        max_key = max(saved, key=lambda k: (saved[k], -k))
    
        return max_key
    
N, P, M = map(int, input().split())
initial = list(map(int, input().split()))
graph = {v:set() for v in range(N)}

for _ in range(P):
    v, w = map(int, input().split())
    graph[v].add(w)
    graph[w].add(v)

answer = solve(graph, initial)
print(answer)

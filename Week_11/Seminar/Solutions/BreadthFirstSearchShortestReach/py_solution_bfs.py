from collections import defaultdict, deque

def bfs(start, graph, N):
    q = deque([start])
    visited = set([start])
    
    results = [-1] * (N + 1)
    results[start] = 0
    
    distance = 1
    
    while q:
        for _ in range(len(q)):
            current = q.popleft()
            
            for child in graph[current]:
                if child not in visited:
                    results[child] = distance
                    q.append(child)
                    visited.add(child)
                    
        distance += 1
        
    results.remove(0)
    results = [r * 6 if r != -1 else -1 for r in results]
    
    return results[1:]


Q = int(input())

for _ in range(Q):
    N, M = map(int, input().split())
    graph = defaultdict(list)

    for _ in range(M):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)
        
    s = int(input())
        
    print(*bfs(s, graph, N))

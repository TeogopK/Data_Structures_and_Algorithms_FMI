from collections import defaultdict, deque

def bfs(start, end, to_visit, forbidden, graph):
    q = deque([start])
    visited = set([start])

    distance = 1

    while q:
        for _ in range(len(q)):
            current = q.popleft()

            for neighbor in graph[current]:
                if neighbor == end:
                    return distance
                    
                if neighbor in visited or neighbor in forbidden or neighbor in to_visit:
                    continue
                
                visited.add(neighbor)
                q.append(neighbor)
        
        distance += 1
        
    return -1
        
def solve():
    total = 0
    
    for i in range(1, P):
        to_visit = set(path[i:])
        total += bfs(path[i - 1], path[i], to_visit, forbidden, graph)
        
    return total

N, M = map(int, input().split())
graph = defaultdict(list)

for _ in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
    
P = int(input())
path = list(map(int, input().split()))

K = int(input())
forbidden = set(map(int, input().split()))

print(solve())

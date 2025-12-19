"""Note that the solution works on Pypy3 and timeouts on Python 3"""
INF = -1

def floyd_warshall(V, paths):
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if paths[i][k] == INF or paths[k][j] == INF:
                    continue
                
                paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]) if paths[i][j] != INF else paths[i][k] + paths[k][j]
                    
    return paths

V, E = map(int, input().split())
V += 1

paths = [[INF for _ in range(V)] for _ in range(V)]

for _ in range(E):
    x, y, w = map(int, input().split())
    paths[x][y] = w
    
for i in range(V):
    paths[i][i] = 0
    
floyd_warshall(V, paths)
    
Q = int(input())
for _ in range(Q):
    x, y = map(int, input().split())
    print(paths[x][y])

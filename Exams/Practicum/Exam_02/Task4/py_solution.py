from collections import deque

N, M = map(int, input().split())

matrix = []
q = deque()
time = 0
infected_count = 0
immune_count = 0

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

for i in range(N):
    row = list(map(int, input().split()))
    matrix.append(row)

    for j in range(M):
        if row[j] == 1:
            immune_count += 1
        elif row[j] == 2:
            q.append((i, j))
            infected_count += 1

while q:
    to_process_count = len(q)

    for _ in range(to_process_count):
        x, y = q.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            if matrix[nx][ny] in (1, 2):
                continue

            matrix[nx][ny] = 2
            infected_count += 1
            q.append((nx, ny))
    time += 1

if immune_count == N * M:
    print(0)
else:
    maximum_infected = N * M - immune_count
    print(time - 1 if infected_count == maximum_infected else -1)

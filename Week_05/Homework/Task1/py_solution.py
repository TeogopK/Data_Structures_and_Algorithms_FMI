from collections import deque


def get_input_apples():
    apples = []

    try:
        while True:
            X, Y = map(int, input().split())
            apples.append((X, Y))
    except Exception:
        pass

    return apples


N, M, T = map(int, input().split())
apples = get_input_apples()

matrix = [(M + 1) * [1] for _ in range(N + 1)]
total_bad = 0

for x, y in apples:
    matrix[x][y] = 0

apples = deque(apples)

for _ in range(T):
    day_count = len(apples)
    total_bad += day_count

    for a in range(day_count):
        x, y = apples.popleft()

        if x + 1 <= N and matrix[x + 1][y]:
            apples.append((x + 1, y))
            matrix[x + 1][y] = 0

        if x - 1 > 0 and matrix[x - 1][y]:
            apples.append((x - 1, y))
            matrix[x - 1][y] = 0

        if y - 1 > 0 and matrix[x][y - 1]:
            apples.append((x, y - 1))
            matrix[x][y - 1] = 0

        if y + 1 <= M and matrix[x][y + 1]:
            apples.append((x, y + 1))
            matrix[x][y + 1] = 0

total_bad += len(apples)
total_ok = N * M - total_bad

print(total_ok)

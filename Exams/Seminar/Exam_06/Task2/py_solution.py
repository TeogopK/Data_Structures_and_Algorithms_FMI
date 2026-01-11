N = int(input())
arr = list(map(int, input().split()))

from collections import defaultdict
from collections import deque

m = defaultdict(int)
q = deque([])

for x in arr:
    q.append(x)
    m[x] += 1

    while q and m[q[0]] > 1:
        q.popleft()

    answer = q[0] if len(q) > 0 else -1
    print(answer, end=" ")

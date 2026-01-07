N, D = map(int, input().split())
arr = list(map(int, input().split()))
results = [-1 for _ in range(N)]
s = []

for i in reversed(range(N)):
    # Remove all that are smaller than the current or outside the window
    while s and (s[-1][1] <= arr[i] or s[-1][0] > i + D):
        s.pop()

    # The answer is the closest, on top of the stack, bigger than the current.
    results[i] = s[-1][0] if s else -1

    # We keep the stack with tuples of index of the number in the array and the number itself
    s.append((i, arr[i]))

print(*results)

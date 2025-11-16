from collections import deque

N, k = map(int, input().split())
arr = [int(i) for i in input().split()]

total = 0
stack = deque()  # indexes of min elements

# Fill the stack with minimums in first k
for i in range(k - 1):
    while stack and arr[stack[-1]] >= arr[i]:
        stack.pop()

    stack.append(i)

# Start calculating
for i in range(k - 1, N):
    while stack and stack[0] < i - k + 1:
        stack.popleft()

    while stack and arr[stack[-1]] >= arr[i]:
        stack.pop()

    stack.append(i)
    total += arr[stack[0]]

print(total)

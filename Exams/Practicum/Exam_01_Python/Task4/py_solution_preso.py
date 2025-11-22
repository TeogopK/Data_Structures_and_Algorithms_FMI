n, d = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
ans = [-1 for _ in range(n)]

stack = []


for i in range(len(arr)):
    while stack and stack[-1][1] < arr[i]:
        ans[stack[-1][0]] = i if stack[-1][0] + d >= i else -1
        stack.pop()

    stack.append((i, arr[i]))


print(*ans)

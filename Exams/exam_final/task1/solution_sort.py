N = int(input())
inputs = [(i, list(map(int, input().split()))) for i in range(1, N + 1)]
inputs.sort(key=lambda value: ((value[1][0] * value[1][0]) / value[1][1], value[1][0]), reverse=True)

output = [value[0] for value in inputs]
print(*output)

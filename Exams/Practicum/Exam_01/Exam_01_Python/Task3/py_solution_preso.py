def can_produce(machines, x, t):
    return sum([max((t - start), 0) // productivity for productivity, start in machines]) >= x


n, x = [int(x) for x in input().split()]

machines = []

for _ in range(n):
    machines.append([int(x) for x in input().split()])

left, right = 0, int(1e12)

while left <= right:
    mid = (left + right) // 2
    if can_produce(machines, x, mid):
        right = mid - 1
    else:
        left = mid + 1

print(left)

from collections import defaultdict

N, K = map(int, input().split())
zones = [int(input()) for _ in range(N)]

m = defaultdict(lambda: [0, 0])  # Cumsum -> ways to get there, earliest index
m[0] = [1, 0]  # We can get to 0 cum_sum in 1 way, it is starting from index 0
cum_sum = 0

groups = 0
max_group = 0


for i, zone in enumerate(zones):
    cum_sum += zone
    m[cum_sum][0] += 1

    if m[cum_sum][1] == 0:  # If it is the first time
        m[cum_sum][1] = i

    if m[cum_sum - K][0] > 0:  # If there is the sum needed
        groups += m[cum_sum - K][0]
        max_group = max(i - m[cum_sum - K][1], max_group)


if groups == 0:
    print(-1)
else:
    print(max_group, groups)

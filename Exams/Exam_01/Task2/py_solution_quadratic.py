# O(N^2) time complexity
# O(N) space complexity


def solve(nums, N):
    N = len(nums)
    counts = [0] * N

    for i in range(N):
        for j in range(N):
            if nums[i] < nums[j] and i != j:
                counts[i] += 1

    return counts


N = int(input())
nums = [int(x) for x in input().split()]

results = solve(nums, N)
print(*results)

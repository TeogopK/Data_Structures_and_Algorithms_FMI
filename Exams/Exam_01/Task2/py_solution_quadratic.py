# O(N^2) time complexity
# O(N) space complexity


def solve(nums, N):
    N = len(nums)
    results = [0] * N

    for i in range(N):
        for j in range(N):
            if nums[i] < nums[j] and i != j:
                results[i] += 1

    return results


N = int(input())
nums = [int(x) for x in input().split()]

results = solve(nums, N)
print(*results)

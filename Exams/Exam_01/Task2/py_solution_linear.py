# O(N + K) time complexity
# O(N + K) space complexity, where K is the max element in the array + 1


def solve(nums, N):
    K = max(nums) + 1
    counts = [0] * K
    results = [0] * N

    # We count the occurences of each number
    for x in nums:
        counts[x] += 1

    # We start a cumulative sum from the end of the array
    for i in range(K - 2, 0, -1):
        counts[i] += counts[i + 1]

    # This way counts[i] shows how many numbers are bigger than the number i - 1
    # Except for the last number, that should not throw index out of range
    for i, x in enumerate(nums):
        results[i] = counts[x + 1] if x != K - 1 else 0

    return results


N = int(input())
nums = [int(x) for x in input().split()]

results = solve(nums, N)
print(*results)

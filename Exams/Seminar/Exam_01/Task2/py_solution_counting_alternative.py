# Alternative syntax solution

# O(N + K) time complexity
# O(N + K) space complexity, where K is the max element in the array + 1


N = int(input())
nums = list(map(int, input().split()))

K = max(nums) + 1
counts = [0] * K
results = [0] * N

# We count the occurences of each number
for x in nums:
    counts[x] += 1

# We start a cumulative sum from the end of the array
for i in reversed(range(K - 1)):
    counts[i] += counts[i + 1]

# This way counts[i] shows how many numbers are bigger than the number i - 1
counts += [0]

for i, x in enumerate(nums):
    results[i] = counts[x + 1]

print(*results)

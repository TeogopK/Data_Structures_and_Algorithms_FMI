# https://www.hackerrank.com/contests/sda-homework-9/challenges/0-1-1

# Prefix sum technique: after turning 0 into -1, a subarray has an equal number
# of 0s and 1s exactly when its sum is 0, i.e. when two prefix sums are equal.
N = int(input())
arr = list(map(int, input().split()))

# Converting all zeros to -1
arr = [el if el == 1 else -1 for el in arr]

# Finding the longest subarray with sum = 0
current_sum = 0
longest = 0

d = {}
d[0] = -1  # the empty prefix ends before index 0

for i, el in enumerate(arr):
    current_sum += el

    if current_sum in d:
        length = i - d[current_sum]
        longest = max(length, longest)
    else:
        d[current_sum] = i

print(longest)

N = int(input())
arr = list(map(int, input().split()))

# Converting all zeros to -1
arr = [el if el == 1 else -1 for el in arr]

# Finding the longest subarray with sum k = 0
current_sum = 0
longest = 0

d = {}
d[0] = 0

for i, el in enumerate(arr):
    current_sum += el
    
    if current_sum in d:
        length = i - d[current_sum]
        longest = max(length, longest)
    else:
        d[current_sum] = i

print(longest)
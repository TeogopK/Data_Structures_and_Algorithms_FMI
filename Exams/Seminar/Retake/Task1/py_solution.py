# генерирано с claude
from collections import Counter

N = int(input())
nums = list(map(int, input().split()))

freq = Counter(nums)

nums.sort(key=lambda x: (freq[x], -x))

print(*nums)

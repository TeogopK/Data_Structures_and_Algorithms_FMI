import bisect

# Решение 1: Използване на list и bisect (аналог на upper_bound)
# Добавяме елементите в списък, сортираме го и търсим с bisect_right

n = int(input())
nums = list(map(int, input().split()))
target = int(input())

# Сортираме списъка
nums.sort()

# bisect_right връща позицията на първия елемент строго по-голям от target
pos = bisect.bisect_right(nums, target)

if pos == len(nums):
    print("NO")
else:
    print(nums[pos])

# Сложност:
# Време: O(N*logN) за сортиране + O(logN) за bisect = O(N*logN)
# Памет: O(N) за списъка

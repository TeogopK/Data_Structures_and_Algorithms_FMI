# Решение 2: Използване на set (не е директен аналог на C++ set, но работи)
# В Python set не поддържа сортиран ред, затова конвертираме в list

n = int(input())
nums_list = list(map(int, input().split()))
target = int(input())

# Използваме set за премахване на дубликати, после сортираме
nums = sorted(set(nums_list))

# Търсим първия елемент строго по-голям от target
result = None
for num in nums:
    if num > target:
        result = num
        break

if result is None:
    print("NO")
else:
    print(result)

# Сложност:
# Време: O(N) за set + O(N*logN) за сортиране + O(N) за търсене = O(N*logN)
# Памет: O(N) за set-a
# Забележка: За по-ефективно решене може да се използва bisect след sorted(set())

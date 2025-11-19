# Решение 4: Линейно търсене
# Просто добавяме всички елементи в масив и търсим линейно

n = int(input())
nums = list(map(int, input().split()))
target = int(input())

# Търсим най-малкото число строго по-голямо от target
result = float('inf')

for num in nums:
    if num > target:
        result = min(result, num)

if result == float('inf'):
    print("NO")
else:
    print(result)

# Сложност:
# Време: O(N) за въвеждане + O(N) за линейно търсене = O(N)
# Памет: O(N) за списъка
# Забележка: Това е най-простото решение, но не най-ефективното при повторни заявки

N = int(input())
arr = [int(x) for x in input().split()]

arr2 = list(set(arr))
arr2.sort()
print(*arr2)

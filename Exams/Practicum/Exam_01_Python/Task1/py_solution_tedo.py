def find_index_of_name(name, arr):
    for i, entry in enumerate(arr):
        if entry[0] == name:
            return i
    return -1


N = int(input())

arr = []
for _ in range(N):
    """Getting the input slowly"""
    name, height = input().split()
    height = int(height)
    arr.append((name, height))

swapped_tuple = tuple(input().split())
arr.sort(key=lambda x: x[1])

index_first = find_index_of_name(swapped_tuple[0], arr)
index_second = find_index_of_name(swapped_tuple[1], arr)

arr[index_first], arr[index_second] = arr[index_second], arr[index_first]

print(*[entry[0] for entry in arr], sep="\n")

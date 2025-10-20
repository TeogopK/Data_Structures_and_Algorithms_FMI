def merge(arr, left_arr, right_arr):
    index = left = right = 0
    left_size = len(left_arr)
    right_size = len(right_arr)

    while left < left_size and right < right_size:
        if left_arr[left] <= right_arr[right]:
            arr[index] = left_arr[left]
            left += 1
        else:
            arr[index] = right_arr[right]
            right += 1
        index += 1

    while left < left_size:
        arr[index] = left_arr[left]
        index += 1
        left += 1

    while right < right_size:
        arr[index] = right_arr[right]
        index += 1
        right += 1


def merge_sort(arr):
    if len(arr) > 1:
        middle = len(arr) // 2

        left_arr = arr[:middle]
        right_arr = arr[middle:]

        merge_sort(left_arr)
        merge_sort(right_arr)

        merge(arr, left_arr, right_arr)


N = int(input())
arr = [int(x) for x in input().split()]

# print(arr)
asdf = list(set(arr))
merge_sort(asdf)
print(*asdf)  # = print(asdf[0], asdf[1], ..., asdf[n])

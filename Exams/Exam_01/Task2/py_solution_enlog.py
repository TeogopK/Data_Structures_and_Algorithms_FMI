# O(NlogN) time complexity
# O(N) space complexity


def solve(nums, N):
    results = [0] * N

    # Adding the index in the starting array for each num
    nums_indexes = [(start_index, x) for start_index, x in enumerate(nums)]

    # Sorting so that the largest element is first
    nums_indexes.sort(key=lambda x: -x[1])

    count = 0
    prev_number = -1  # Invalid value

    for i, (start_index, x) in enumerate(nums_indexes):
        # If we have the same number we do not increase the count
        if prev_number != x:
            count = i
            prev_number = x

        # The largest number will have 0 before it. The next one will have *i*, if it is different.
        # This is based on the different numbers before the current number in the sorted array.
        results[start_index] = count

    return results


N = int(input())
nums = [int(x) for x in input().split()]

results = solve(nums, N)
print(*results)

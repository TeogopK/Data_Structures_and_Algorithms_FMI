def can_divide_upto(max_sum, max_teams_count, arr):
    groups = 1
    current_sum = 0

    for el in arr:
        current_sum += el

        if current_sum > max_sum:
            groups += 1
            current_sum = el

        if groups > max_teams_count:
            return False

    return True


def binary_search_rightmost(arr, teams_count):
    left = max(arr)  # Lower limit for the best sum is the largest number to be alone
    right = sum(arr)  # Larger number than the best sum is all to be in one group

    best_sum = right

    while left <= right:
        mid = left + (right - left) // 2

        if can_divide_upto(mid, teams_count, arr):
            right = mid - 1
            best_sum = mid
        else:
            left = mid + 1

    return best_sum


_, T = map(int, input().split())
arr = [int(el) for el in input().split()]

best_sum = binary_search_rightmost(arr, T)
print(best_sum)

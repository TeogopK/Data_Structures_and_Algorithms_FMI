import bisect
INVALID_OUTPUT = -1

def is_right_closer(target, bigger, smaller):
    """Checks if the bigger number is closer to the target value than the smaller number.
    If target = 5, bigger = 10, smaller = 4 will choose 4 (False),
    If target = 9, bigger = 10, smaller = 4 will choose 10 (True),
    If target = 5, bigger = 6, smaller = 4 will choose 6 (True),
    """
    return abs(bigger - target) <= abs(smaller - target)

def find_left_of_closest(target, arr):
    """Finds the closest number to target and 
        returns the number on the right of the closest one."""
    insert_indx = bisect.bisect(arr, target)
    if insert_indx >= N:
        return INVALID_OUTPUT
    
    bigger_indx = insert_indx
    smaller_indx = max(insert_indx - 1, 0)
    
    closest_indx = bigger_indx if is_right_closer(target, arr[bigger_indx], arr[smaller_indx]) else smaller_indx

    # If it was just the closest num -> return arr[closest_indx]
    return arr[closest_indx + 1] if closest_indx != N - 1 else INVALID_OUTPUT

N = int(input())
arr = list(map(int, input().split()))

Q = int(input())
queries = [int(input()) for _ in range(Q)]
    
arr.reverse() # To work with bisect

for num in queries:
    output = find_left_of_closest(num, arr)
    print(output)
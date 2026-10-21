"""The function can either check here similar to FirstBadVersion"""


def check(seconds_passed, total_papers, printers_times):
    ready_papers = [seconds_passed // time_for_one for time_for_one in printers_times]

    return sum(ready_papers) >= total_papers


def binary_search(arr, total):
    l = 0
    r = total * sum(arr)  # Upper limit

    answ = r

    while l <= r:
        m = (l + r) // 2

        if check(m, total, arr):
            r = m - 1
            answ = m
        else:
            l = m + 1

    return answ


N, K = map(int, input().split())
printers_times = [int(i) for i in input().split()]

min_time = binary_search(printers_times, N)
print(min_time)

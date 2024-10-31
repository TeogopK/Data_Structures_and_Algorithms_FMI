def binary(intervals, end_i):
    ans = -1
    left, right = 0, len(intervals) - 1
    while left <= right:
        mid = (left + right) // 2
        if intervals[mid][0] >= end_i:
            ans = intervals[mid][2]
            right = mid - 1
        else:
            left = mid + 1

    return ans

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        ans = [-1 for _ in intervals]
        intervals = [(start, end, i) for i, (start, end) in enumerate(intervals)]
        intervals.sort(key=lambda x: x[0])

        # What is the complexity here?
        for interval in intervals:
            ans[interval[2]] = binary(intervals, interval[1])

        return ans
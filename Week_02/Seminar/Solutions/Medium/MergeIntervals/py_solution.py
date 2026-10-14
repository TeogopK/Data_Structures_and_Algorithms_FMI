class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        n = len(intervals)
        output = [intervals[0]]
        for i in range(1, n):
            if intervals[i][0] <= output[-1][1]:
                output[-1][1] = max(output[-1][1],intervals[i][1])
            else:
                output.append(intervals[i])
        return output
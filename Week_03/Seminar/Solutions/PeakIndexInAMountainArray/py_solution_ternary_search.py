"""Using ternary search to find the maximum of parabolic function"""


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l = 0
        r = len(arr) - 1

        while l <= r:
            mid1 = l + (r - l) // 3
            mid2 = r - (r - l) // 3

            if arr[mid1] < arr[mid2]:
                l = mid1 + 1
            else:
                r = mid2 - 1

        return l

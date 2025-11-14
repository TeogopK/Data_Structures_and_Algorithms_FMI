class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        low, high = len(nums) - 1, 0

        # monotonically increasing stack
        stack = []    
        for i, num in enumerate(nums):
            while stack and stack[-1][1] > num:
                ind, last = stack.pop()
                low = min(low, ind)

            stack.append((i, num))

        # monotonically decreasing stack
        stack = []       
        for i, num in enumerate(reversed(nums)):
            while stack and stack[-1][1] < num:
                ind, last = stack.pop()
                high = max(high, ind)

            stack.append((len(nums) - 1 - i, num))

        # low >= high means array is already sorted
        return 0 if low >= high else high - low + 1
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        N = len(nums)

        max_list = []
        d = deque()  # indexes of max elements

        # Fill the equed with maximums in first k
        for i in range(k - 1):
            while d and nums[d[-1]] <= nums[i]:
                d.pop()

            d.append(i)

        # Start calculating
        for i in range(k - 1, N):
            while d and d[0] < i - k + 1:
                d.popleft()

            while d and nums[d[-1]] <= nums[i]:
                d.pop()

            d.append(i)
            max_list.append(nums[d[0]])

        return max_list

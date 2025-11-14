from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        dq = deque()

        for i in range(len(nums)):
            # Remove all numbers in the back, which are less than the incoming
            # We keep it decreasing that way, so that the front is always the answer
            while dq and dq[-1] < nums[i]:
                dq.pop()
                
            dq.append(nums[i])

            # We are removing the max
            if i >= k and dq[0] == nums[i - k]:
                dq.popleft()
            
            if i >= k - 1:
                ans.append(dq[0])

        return ans


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        # 1 5 4 3 2 5 1 6
        # Keep monotically decrease stack, that way when we reach bigger number than
        # the top, we can pop all lesser elements

        ans = [-1 for _ in nums]

        stack = []

        # We will do 2 passes, since it is circular
        for _ in range(2):
            for i, num in enumerate(nums):

                while stack and stack[-1][1] < num:
                    ans[stack[-1][0]] = num
                    stack.pop()

                stack.append((i, num))

        return ans
            
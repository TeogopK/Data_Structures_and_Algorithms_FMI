class Solution:
    def rob(self, nums: List[int]) -> int:
        ans = [0 for _ in nums] + [0, 0]

        for i, num in enumerate(nums):
            ans[i + 2] = max(ans[i + 1], num + ans[i])

        return max(ans)
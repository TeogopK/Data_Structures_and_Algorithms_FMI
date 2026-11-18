# https://leetcode.com/problems/range-sum-query-immutable/


class NumArray:
    def __init__(self, nums: List[int]):
        # prefix[i] = sum of nums[0..i-1], prefix[0] = 0
        self.prefix = [0]
        for num in nums:
            self.prefix.append(self.prefix[-1] + num)

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right + 1] - self.prefix[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums = [(idx, num) for idx, num in enumerate(nums)]
        nums.sort(key=lambda x: x[1])
        # print(nums)

        left = 0
        right = len(nums) - 1

        while left < right:
            # print(left, right)
            if nums[left][1] + nums[right][1] > target:
                right -= 1

            elif nums[left][1] + nums[right][1] < target:
                left += 1

            elif nums[left][1] + nums[right][1] == target:
                return [nums[left][0], nums[right][0]]

        return "asdf"

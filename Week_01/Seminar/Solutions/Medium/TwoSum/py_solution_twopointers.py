class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums2 = list(sorted(nums))

        left = 0
        right = len(nums) - 1

        while left < right:
            if nums2[left] + nums2[right] == target:
                return [nums.index(nums2[left]), len(nums) - 1 - nums[::-1].index(nums2[right])]

            elif nums2[left] + nums2[right] < target:
                left += 1
            else:
                right -= 1

        return []

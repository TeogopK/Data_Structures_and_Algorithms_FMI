class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1

        res = nums[0]
        while left <= right:
            mid = left + int((right - left) / 2)

            if nums[left] == nums[right]:
                res = min(res, nums[left])
                left += 1
                right -= 1                
            elif nums[left] <= nums[mid]:
                res = min(res, nums[left])
                left = mid + 1
            else:
                res = min(res, nums[mid])
                right = mid - 1

        return res
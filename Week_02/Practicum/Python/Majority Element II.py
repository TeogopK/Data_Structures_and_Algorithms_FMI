class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        nums.sort()
        output = []
        print(nums)
        target = len(nums) // 3
        for i in range(len(nums) - target):
            if nums[i] == nums[i + target] and nums[i] not in output:
                output.append(nums[i])

        return output
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return False
            
        s = set()
        left = 0

        for right in range(len(nums)):
            if nums[right] in s:
                return True

            if right >= k:
                s.remove(nums[left])
                left += 1

            s.add(nums[right])

        return False
    
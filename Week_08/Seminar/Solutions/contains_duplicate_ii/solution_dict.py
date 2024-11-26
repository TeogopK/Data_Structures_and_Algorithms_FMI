class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for index, number in enumerate(nums):
            if number in d and d[number] >= index - k:
                return True

            d[number] = index
            
        return False

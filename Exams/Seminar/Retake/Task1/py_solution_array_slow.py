class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        result = nums.copy()
        result.sort(key=lambda x: (nums.count(x), -x))
        return result

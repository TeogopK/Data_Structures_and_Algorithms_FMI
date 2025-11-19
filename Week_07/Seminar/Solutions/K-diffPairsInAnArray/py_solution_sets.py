class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        seen = set()
        smaller = set()

        for el in nums:
            if el + k in seen:
                smaller.add(el)
                
            if el - k in seen:
                smaller.add(el - k)

            seen.add(el)

        return len(smaller)
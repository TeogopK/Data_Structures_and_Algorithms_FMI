class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        set_unique_candies = set(candyType)

        return min(len(set_unique_candies), len(candyType) // 2)
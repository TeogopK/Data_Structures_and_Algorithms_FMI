class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        count = [0 for _ in range(10**4 + 1)]
        for num in nums:
            count[abs(num)] += 1

        ans = []

        for num, num_count in enumerate(count):  # O(K)
            ans.extend([num**2 for _ in range(num_count)])  # O(N)
        # Total O(K) + O(N)

        return ans

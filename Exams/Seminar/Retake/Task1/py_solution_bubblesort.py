class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        from collections import defaultdict

        freq = defaultdict(int)

        # Count frequencies
        for x in nums:
            freq[x] += 1

        # Bubble sort
        n = len(nums)

        for i in range(n):
            for j in range(0, n - i - 1):
                a = nums[j]
                b = nums[j + 1]

                # Swap if a should come after b
                if freq[a] > freq[b] or (
                    freq[a] == freq[b] and a < b
                ):
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
            print(nums) # Each iteration the newest last number is in the correct place

        return nums

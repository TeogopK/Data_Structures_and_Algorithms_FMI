class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = current_sum = sum(nums[:k])

        for i in range(len(nums) - k):  # O(n)
            # print(i, i + k)
            current_sum = current_sum - nums[i] + nums[i + k]

            ans = max(ans, current_sum)

        return ans / k

class Solution:
    def lengthOfLIS(self, nums) -> int:
        dp = []
        for i in range(len(nums)):
            # for each i we will give an answer what is the length of the LIS that ends with 
            # nums[i]. The base case is 1, each number can make a subsequence of length 1.
            dp.append(1)
            for j in range(i):
                if nums[j] < nums[i]:
                    # If a number before nums[i] is lower than nums[i], then we can
                    # make a longer increasing subsequence by 1 over the one we can make
                    # ending with nums[j]
                    dp[i] = max(dp[i], dp[j] + 1)


        return max(dp)

            
            
        
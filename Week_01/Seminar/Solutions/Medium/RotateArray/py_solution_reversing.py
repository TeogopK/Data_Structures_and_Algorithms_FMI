class Solution:
    # O(n) time | O(1) space
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)
        k %= n

        def reverse(start, end):
            while start < end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1

        reverse(0, n - 1)  # Reverse whole array
        reverse(0, k - 1)  # Reverse first k
        reverse(k, n - 1)  # Reverse rest

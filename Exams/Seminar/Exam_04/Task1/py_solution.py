def longestSubarray(nums, k):
    freq = {}
    left = 0
    best = 0

    for right in range(len(nums)):
        x = nums[right]
        freq[x] = freq.get(x, 0) + 1

        while freq[x] > k:
            y = nums[left]
            freq[y] -= 1
            left += 1

        best = max(best, right - left + 1)

    return best

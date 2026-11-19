# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        max_length = 0
        start = 0

        for index, char in enumerate(s):
            if char in d:
                last_position = d[char]
                if last_position < start:
                    pass
                else:
                    max_length = max(max_length, index - start)
                    start = last_position + 1
            d[char] = index

        return max(max_length, len(s) - start)

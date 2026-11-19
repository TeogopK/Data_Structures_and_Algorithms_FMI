# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        char_set = set()
        left = 0

        for right in range(len(s)):
            if s[right] not in char_set:
                char_set.add(s[right])
                max_length = max(max_length, right - left + 1)
            else:
                while s[right] in char_set:
                    char_set.remove(s[left])
                    left += 1
                char_set.add(s[right])

        return max_length

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        c1, c2 = [0 for _ in range(26)], [0 for _ in range(26)]

        for c in s:
            c1[ord(c) - ord('a')] += 1
        
        for c in t:
            c2[ord(c) - ord('a')] += 1

        for c in range(26):
            if c1[c] != c2[c]:
                return False

        return True
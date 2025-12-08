class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        prev = [0] * (n + 1)
        
        for i in range(m - 1, -1, -1):
            cur = [0] * (n + 1)
            for j in range(n - 1, -1, -1):
                if text1[i] == text2[j]:
                    cur[j] = 1 + prev[j + 1]
                else:
                    cur[j] = max(prev[j], cur[j + 1])
            prev = cur
        return cur[0]
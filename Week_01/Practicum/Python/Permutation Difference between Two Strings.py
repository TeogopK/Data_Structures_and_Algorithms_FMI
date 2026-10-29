class Solution:
    def findPermutationDifference(self, s: str, t: str) -> int:
        sum_ = 0
        for i, char_s in enumerate(s):
            for j, char_t in enumerate(t):
                if char_s == char_t:
                    sum_ += abs(i - j)

        return sum_
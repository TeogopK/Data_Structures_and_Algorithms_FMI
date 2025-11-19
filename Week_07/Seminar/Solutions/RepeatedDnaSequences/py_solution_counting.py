from collections import defaultdict
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        counts = defaultdict(int)

        for i in range(len(s) - 9):
            counts[s[i:i+10]] += 1

        return [k for k, v in counts.items() if v > 1]
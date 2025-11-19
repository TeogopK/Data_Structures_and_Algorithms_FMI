class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        results = set()

        for i in range(len(s) - 9):
            if s[i:i+10] in s[i+1:]:
                results.add(s[i:i+10])

        return list(results)
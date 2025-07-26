import bisect

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        idx = bisect.bisect_right(letters, target)
        letters.append(letters[0])
        return letters[idx]
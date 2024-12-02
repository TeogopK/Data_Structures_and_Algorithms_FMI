class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        s = set()
        ans = 0

        for roll in rolls:
            s.add(roll)
            if len(s) == k:
                s = set()
                ans += 1

        return ans + 1
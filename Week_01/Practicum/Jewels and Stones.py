class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        res = 0
        for stone in stones:
            for jewel in jewels:
                if stone == jewel:
                    res += 1
                    break

        return res
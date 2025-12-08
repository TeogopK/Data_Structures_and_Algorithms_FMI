def coins_dyn(coins, amount):
    if amount < 0:
        return int(1e12)
    if amount == 0:
        return 0

    ans = [(coins_dyn(coins, amount - x)) for x in coins]
    
    return min(ans) + 1

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        ans = coins_dyn(coins, amount) 
        return ans if ans < int(1e12) else -1
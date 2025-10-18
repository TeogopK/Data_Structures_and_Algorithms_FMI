class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        
        total_ice_creams = 0
        i = 0
        while i < len(costs) and costs[i] <= coins:
            total_ice_creams += 1
            coins -= costs[i]
            i += 1

        return total_ice_creams
            

        
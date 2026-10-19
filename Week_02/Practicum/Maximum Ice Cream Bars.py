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


class SolutionCountingSort:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        counts = [0] * (max(costs) + 1)
        for cost in costs:
            counts[cost] += 1

        total_ice_creams = 0
        total_spent = 0
        for cost in range(1, len(counts)):
            while counts[cost] > 0 and total_spent + cost <= coins:
                total_spent += cost
                total_ice_creams += 1
                counts[cost] -= 1

            if total_spent + cost > coins:
                break

        return total_ice_creams

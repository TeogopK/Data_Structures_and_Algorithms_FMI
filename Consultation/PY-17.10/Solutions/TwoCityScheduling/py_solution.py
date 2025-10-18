class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs_sorted = sorted(costs, key=lambda x: x[1] - x[0])

        total_cost = 0
        for i in range(len(costs_sorted)):
            if i < len(costs_sorted) // 2:
                total_cost += costs_sorted[i][1]
            else:
                total_cost += costs_sorted[i][0]
            
        return total_cost
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        count_lst = [0 for _ in range(int(1e5) + 1)]

        total_ice_creams = 0

        for cost in costs:
            count_lst[cost] += 1

        for num, num_count in enumerate(count_lst):
            if num_count == 0:
                continue

            target = coins // num

            if num_count > target:
                total_ice_creams += target
                break
            
            total_ice_creams += num_count
            coins -= num_count * num

        return total_ice_creams
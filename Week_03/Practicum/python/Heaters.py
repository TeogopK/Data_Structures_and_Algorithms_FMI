class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        n = len(houses)
        m = len(heaters)
        
        heaters.sort()
        ans = 0
        
        # For each house we will find the closest heater to it
        for house in houses:
            index = bisect.bisect_left(heaters, house)

            if index==0:
                nearest_heater_distance = heaters[0] - house
            elif index==m:
                nearest_heater_distance = house - heaters[-1]
            else:
                nearest_heater_distance = min(heaters[index]-house, house - heaters[index-1])
            
            ans = max(ans, nearest_heater_distance)
        
        return ans
    
# Binary search over function heat
class Solution:
    def heat(self, houses, heaters, n):
        i_heater = 0
        num_heated = 0

        for house in houses:
            # print(house, i_heater, heaters[i_heater] - n <= house <= heaters[i_heater] + n)

            while i_heater < len(heaters) and not heaters[i_heater] - n <= house <= heaters[i_heater] + n:
                i_heater += 1

            if i_heater == len(heaters):
                return False

            if heaters[i_heater] - n <= house <= heaters[i_heater] + n:
                num_heated += 1
                continue
            
        return num_heated == len(houses)

    def binary_search(self, left, right, houses, heaters):
        ans = -1
        while left <= right:
            mid = (left + right) // 2
            # print(left, right, mid, self.heat(houses, heaters, mid))
        
            if self.heat(houses, heaters, mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans

    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        return self.binary_search(0, int(1e10), houses, heaters)
        self.heat(houses, heaters, 2)
        return 1
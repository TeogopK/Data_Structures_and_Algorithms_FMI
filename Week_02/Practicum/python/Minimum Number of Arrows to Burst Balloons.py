class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        baloons = sorted(points, key=lambda x: (x[0], x[1]))
        counter = 0
        last_bursted = -1
        for i in range(len(baloons)):
            if i <= last_bursted:
                continue

            # Burst the baloon, while aiming at its tail (baloons[i][1]) initially
            j = i
            burst_location = baloons[i][1]
            counter += 1
            while j < len(baloons) and baloons[j][0] <= burst_location:
                last_bursted += 1
                # Greedily move the burst location to the front
                burst_location = min(burst_location, baloons[j][1])
                j += 1
                

        return counter
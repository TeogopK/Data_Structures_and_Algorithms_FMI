class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        times = [time + [i] for i, time in enumerate(times)]
        times.sort(key=lambda x: x[0])
        print(times)

        chairs = [i for i in range(len(times))]
        print(chairs)
        leaving = []

        for time in times:
            current_time, leaving_time, idx = time
            while leaving and leaving[0][0] <= current_time:
                _, free_chair = heapq.heappop(leaving)
                heapq.heappush(chairs, free_chair)

            occupied_chair = heapq.heappop(chairs)

            if idx == targetFriend:
                return occupied_chair

            heapq.heappush(leaving, (leaving_time, occupied_chair))

        return 1
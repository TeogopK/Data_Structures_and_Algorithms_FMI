import heapq

class SeatManager:

    def __init__(self, n: int):
        self.seats = [seat for seat in range(1, n + 1)]
        # heapq.heapify(self.seats)

    def reserve(self) -> int:
        smallest = heapq.heappop(self.seats)
        return smallest

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.seats, seatNumber)


# Your SeatManager object will be instantiated and called as such:
# obj = SeatManager(n)
# param_1 = obj.reserve()
# obj.unreserve(seatNumber)
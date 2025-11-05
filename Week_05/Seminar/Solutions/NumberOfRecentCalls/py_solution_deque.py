from collections import deque

class RecentCounter:
    _PING_RANGE = 3000

    def __init__(self):
        self.d = deque()

    def ping(self, t: int) -> int:
        while self.d and self.d[0] < t - self._PING_RANGE:
            self.d.popleft()
        self.d.append(t)

        return len(self.d)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
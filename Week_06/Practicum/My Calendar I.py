from sortedcontainers import SortedList

class MyCalendar:

    def __init__(self):
        # You can treat this SortedList as Balanced Binary Search Tree
        self.calendar_list = SortedList([])

    def book(self, startTime: int, endTime: int) -> bool:
        # Binary Seach, find the index where we would insert that time
        idx = self.calendar_list.bisect_left((startTime, endTime)) # O(log(N))
        
        # If the previous interval collides
        if idx > 0 and self.calendar_list[idx - 1][1] > startTime:
            return False
        # If the next interval collides
        if idx < len(self.calendar_list) and self.calendar_list[idx][0] < endTime:
            return False

        # If no intervals collide
        self.calendar_list.add((startTime, endTime)) # O(log(N))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)
from sortedcontainers import SortedDict, SortedList
# The sorted dict will keep the keys in a binary search tree, so that we can access
# them in O(log(N))

class StockPrice:

    def __init__(self):
        self.min_max_list = SortedList([]) # Keep all prices here sorted
        self.timestamp_dict = SortedDict([]) # Keep the price for each timestamp, coulde be a normal dict as well...
        self.max_timestamp = 0

    def update(self, timestamp: int, price: int) -> None:
        # If the stock is already in our dictionary 
        if self.max_timestamp and timestamp in self.timestamp_dict:
            # Remove the current price from the list
            current_price = self.timestamp_dict[timestamp]
            self.min_max_list.remove(current_price)
        
        self.min_max_list.add(price)
        self.timestamp_dict[timestamp] = price
        self.max_timestamp = max(self.max_timestamp, timestamp)

    def current(self) -> int:
        return self.timestamp_dict[self.max_timestamp]

    def maximum(self) -> int:
        return self.min_max_list[-1]

    def minimum(self) -> int:
        return self.min_max_list[0]
        


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
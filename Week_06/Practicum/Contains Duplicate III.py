from sortedcontainers import SortedList


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        # We will use a sliding window with sorted elements. It will be of size indexDiff + 1.
        # Once a new num enters we will check "all" of the numbers on its left. By the time
        # it exits the sliding window it would have been checked by "all" of the numbers
        # on its right. Of course we would not check them all every single time.
        # when a new number enters the sliding we compare it only to the element on the left
        # and right to the place where it would be inserted to keep the list sorted.
        lst = SortedList([])
        for i, num in enumerate(nums):
            if i > indexDiff:
                lst.remove(nums[i - indexDiff - 1])

            # The same logic with the calendar. Check the previous and next number
            idx = lst.bisect_left(num)
            if idx > 0 and abs(lst[idx - 1] - num) <= valueDiff:
                return True
                
            if idx < len(lst) and abs(lst[idx] - num) <= valueDiff:
                return True        

            lst.add(num)

        return False
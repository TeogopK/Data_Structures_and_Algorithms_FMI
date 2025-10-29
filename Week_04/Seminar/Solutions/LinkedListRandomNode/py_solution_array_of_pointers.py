# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def __init__(self, head: Optional[ListNode]):
        current = head
        self.size = 0
        self.pointers_map = []  # idx -> ListNode()

        while current != None:
            self.pointers_map.append(current)
            self.size += 1
            current = current.next

    def getRandom(self) -> int:
        random_idx = randint(0, self.size - 1)  # -> O(1)
        return self.pointers_map[random_idx].val  # -> O(1)


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()

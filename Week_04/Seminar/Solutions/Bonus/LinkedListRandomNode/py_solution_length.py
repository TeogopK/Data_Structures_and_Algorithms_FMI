# https://leetcode.com/problems/linked-list-random-node/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head
        self.size = 0

        current = head
        while current:
            self.size += 1
            current = current.next

    def getRandom(self) -> int:
        steps = random.randint(0, self.size - 1)

        current = self.head
        for _ in range(steps):
            current = current.next

        return current.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()

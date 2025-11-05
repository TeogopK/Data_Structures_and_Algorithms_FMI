# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:

        lst = []
        while head:
            lst.append(head.val)
            head = head.next

        output = [0] * len(lst)

        stack_ = []

        for i in range(len(lst) - 1, -1, -1):
            while stack_ and stack_[-1] <= lst[i]:
                stack_.pop()

            output[i] = 0 if not stack_ else stack_[-1]
            stack_.append(lst[i])

        return output

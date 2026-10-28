# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""Note that this solution will time out due to O(N^2) time complexity."""
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        i = headA

        while i:
            j = headB

            while j:
                if i == j:
                    return i

                j = j.next
                
            i = i.next

        return None
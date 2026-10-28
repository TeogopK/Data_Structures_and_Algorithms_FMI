# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""Solution that equalizes the paths by returning to the opposite beginning - O(N)."""


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        iterA = headA
        iterB = headB

        has_jumped = False

        while iterA != iterB:
            iterA = iterA.next
            iterB = iterB.next

            if not iterA:
                iterA = headB

                if has_jumped:
                    return None

                has_jumped = True

            if not iterB:
                iterB = headA

        return iterA

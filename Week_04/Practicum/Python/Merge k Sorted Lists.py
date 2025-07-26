# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def mergeTwo(self, left: ListNode, right: ListNode):
        
        merged = ListNode()
        curr = merged
        
        while left is not None and right is not None:

            if left.val < right.val:
                left, curr.next = left.next, left
            else:
                right, curr.next = right.next, right
            curr = curr.next

        curr.next = left or right
        return merged.next

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]

        cnt = 1
        while cnt < len(lists):
            for i in range(0, len(lists) - cnt, cnt*2):
                lists[i] = self.mergeTwo(lists[i], lists[i + cnt])
            cnt *= 2

        return lists[0]R
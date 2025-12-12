# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []

        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(pq, (lists[i].val, i))
                lists[i] = lists[i].next

        ans = None

        while pq:
            list_val, list_idx = heapq.heappop(pq)
            
            new_node = ListNode(list_val)

            if not ans:
                ans = curr = new_node
            else:
                curr.next = new_node
                curr = curr.next

            if lists[list_idx]:
                heapq.heappush(pq, (lists[list_idx].val, list_idx))
                lists[list_idx] = lists[list_idx].next

        return ans
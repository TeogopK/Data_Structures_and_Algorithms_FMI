# Alternative way of constructing the solution with Infinite loop
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        current = head

        while True: # We start looping infinitely...
            if not current: # and when acess a potential None - we check and stop
                break

            next_element = current.next

            if not next_element: # same thing because of the lines belows
                break

            if current.val == next_element.val:
                current.next = next_element.next
                continue 
                # Think about 1->1->1->2->3, what will happen if we switch too early

            current = next_element

        return head
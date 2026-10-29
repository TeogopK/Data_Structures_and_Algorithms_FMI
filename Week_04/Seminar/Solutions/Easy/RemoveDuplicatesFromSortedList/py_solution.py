class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None # Will work without this check, but it is a good practice to add it

        current = head

        while current and current.next:
            next_element = current.next

            if current.val == next_element.val:
                current.next = next_element.next
                continue 
                # Think about 1->1->1->2->3, what will happen if we switch too early

            current = next_element

        return head
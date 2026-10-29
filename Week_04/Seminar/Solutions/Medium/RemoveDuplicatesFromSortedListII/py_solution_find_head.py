# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

"""The solution if you did not use a dummy node like the main solution and instead find the head first."""


def deleteDuplicates(self, head: ListNode | None) -> ListNode | None:
    # skip duplicate groups at the front to find the real head
    while head and head.next and head.val == head.next.val:
        group_value = head.val
        while head and head.val == group_value:
            head = head.next

    if not head:
        return None

    # head is now unique, so it can act as the initial prev
    prev, current = head, head.next

    while current:
        if current.next and current.val == current.next.val:
            group_value = current.val
            while current and current.val == group_value:
                current = current.next
            prev.next = current
        else:
            prev = current
            current = current.next

    return head

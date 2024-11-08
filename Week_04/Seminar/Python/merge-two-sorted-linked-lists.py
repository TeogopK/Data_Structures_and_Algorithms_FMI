#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#

def mergeLists(head1, head2):
    node1 = head1
    node2 = head2

    merged_head = None
    merged_tail = None

    while node1 is not None and node2 is not None:
        if node1.data <= node2.data:
            if merged_head is None:
                merged_head = node1
            else:
                merged_tail.next = node1

            merged_tail = node1

            node1_next = node1.next
            node1.next = None
            node1 = node1_next
        else:
            if merged_head is None:
                merged_head = node2
            else:
                merged_tail.next = node2

            merged_tail = node2

            node2_next = node2.next
            node2.next = None
            node2 = node2_next

    if node1 is not None:
        if merged_tail is None:
            merged_head = node1
            merged_tail = node1
        else:
           merged_tail.next = node1

    if node2 is not None:
        if merged_tail is None:
            merged_head = node2
            merged_tail = node2
        else:
           merged_tail.next = node2

    return merged_head

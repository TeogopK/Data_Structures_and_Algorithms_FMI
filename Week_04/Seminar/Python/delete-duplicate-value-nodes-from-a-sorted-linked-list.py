#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#

def removeDuplicates(llist):
    node = llist

    while node is not None:
        new_next = node.next

        while new_next is not None and new_next.data == node.data:
            new_next = new_next.next

        node.next = new_next
        node = new_next

    return llist

#
# Complete the 'deleteNode' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts following parameters:
#  1. INTEGER_SINGLY_LINKED_LIST llist
#  2. INTEGER position
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#


def deleteNode(llist, position):
    if llist is None:
        return llist

    if position == 0:
        return llist.next

    current = llist

    for _ in range(position - 1):
        if current is None:
            return llist
        current = current.next

    if current is None:
        return llist

    current.next = current.next.next if current.next else None

    return llist

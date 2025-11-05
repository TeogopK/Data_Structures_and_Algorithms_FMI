#
# Complete the 'insertNodeAtPosition' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts following parameters:
#  1. INTEGER_SINGLY_LINKED_LIST llist
#  2. INTEGER data
#  3. INTEGER position
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#


def insertNodeAtPosition(head_node, data, position):
    new_node = SinglyLinkedListNode(data)

    if not head_node:
        return head_node

    current_index = 1
    current_node = head_node

    while current_index < position and current_node:
        current_index += 1
        current_node = current_node.next

    new_node.next = current_node.next
    current_node.next = new_node

    return head_node

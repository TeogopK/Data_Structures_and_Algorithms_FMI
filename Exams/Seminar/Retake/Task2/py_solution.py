# генерирано с claude
from typing import Optional


class Node:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next


def processList(head: Optional[Node]) -> Node:
    if not head:
        return Node(0)

    removed_count = 0
    previous_value = head.data

    last = head
    current = head.next

    while current:
        next_node = current.next
        current_value = current.data

        if current_value == previous_value + 1:
            last.next = next_node
            removed_count += 1
        else:
            last = current

        previous_value = current_value
        current = next_node

    last.next = Node(removed_count)

    return head

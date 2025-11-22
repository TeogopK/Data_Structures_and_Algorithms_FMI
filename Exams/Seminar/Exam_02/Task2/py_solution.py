from typing import Optional


class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node


def positiveStalinSort(lst: Optional[Node]) -> Optional[Node]:
    if not lst:
        return None

    head = lst

    # Премахваме отрицателните в началото
    while head and head.data < 0:
        head = head.next_node

    current = head
    while current and current.next_node:
        # Свързваме текущия с по-следващия елемент, изтривайки по-малкия следващ
        if current.data > current.next_node.data:
            # Не е нужно да търсим `if current.next_node.data < 0 or current.data > current.next_node.data:`,
            # тъй като или ще имаме само отрицателни в началото и празен списък, или поне едно по-голямо от тях.
            current.next_node = current.next_node.next_node
            continue
        # В противен случай продължаваме напред
        else:
            current = current.next_node

    return head

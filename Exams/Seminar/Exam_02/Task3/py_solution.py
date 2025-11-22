from typing import Optional


class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node


def partition(lst: Optional[Node], x: int) -> Optional[Node]:
    if not lst:
        return None

    # Използваме техниката "Sentinel notes", така че решението ние да има общ вид
    before_head = Node(0)
    after_head = Node(0)

    # Итераторите ни за съответните списъци
    before = before_head
    after = after_head

    current = lst
    while current:
        if current.data < x:
            before.next_node = current
            before = before.next_node
        else:
            after.next_node = current
            after = after.next_node
        current = current.next_node

    # Слагаме край на списъка
    after.next_node = None

    # Свързваме края на първия списък с началото на втория, пропускайки началния буферен възел
    before.next_node = after_head.next_node

    # Премахваме началния буферен възел на първия (конкатениран) списък и връщаме главата
    return before_head.next_node

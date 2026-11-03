# Контролно 2 СДА 2026/27, Вариант 2, Задача 2 - filterRocksSortDesc

# O((N + M)^2) time complexity, where N and M are the lengths of the two lists
# O(1) additional space complexity - we reuse the nodes of the input lists
# The solution doesn't use the fact that the input lists are sorted


class ListNode:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def insert_sorted_desc(head, node):
    # Inserts node into the list head, sorted in descending order,
    # and returns the (possibly new) head
    if head is None or node.value > head.value:
        node.next = head
        return node

    # Find the last node with value >= node.value
    current = head
    while current.next and current.next.value >= node.value:
        current = current.next

    node.next = current.next
    current.next = node
    return head


def insert_all(result, lst):
    # Skips the rock nodes of lst and inserts the others one by one into result
    while lst:
        next_node = lst.next

        if lst.value != 0:
            result = insert_sorted_desc(result, lst)

        lst = next_node

    return result


def filterRocksSortDesc(first, second):
    result = None
    result = insert_all(result, first)
    result = insert_all(result, second)
    return result

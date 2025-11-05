# ===============================
# Задача 2 (25т) - Тестове
# ===============================
from typing import Optional


class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node


def positiveStalinSort(lst: Optional[Node]) -> Optional[Node]:
    """Напиши твоето решение тук!"""
    if not lst:
        return None

    head = lst
    while head and head.data < 0:
        head = head.next_node

    current = head
    while current and current.next_node:
        if current.data > current.next_node.data:
            current.next_node = current.next_node.next_node
            continue
        else:
            current = current.next_node

    return head


# ====== Хелпери ======


def list_to_linked(lst):
    """Конвертира Python списък в свързан списък."""
    if not lst:
        return None
    head = Node(lst[0])
    current = head
    for value in lst[1:]:
        current.next_node = Node(value)
        current = current.next_node
    return head


def linked_to_list(node):
    """Конвертира свързан списък обратно в Python списък."""
    result = []
    while node:
        result.append(node.data)
        node = node.next_node
    return result


# ====== Тестове ======


def test_positiveStalinSort():
    tests = [
        ([1, -2, 3, -4, 2, 5], [1, 3, 5]),
        ([-1, 2, -4, 3, 4, 6], [2, 3, 4, 6]),
        ([1, 2, 3, 4, 5], [1, 2, 3, 4, 5]),  # Възходящ ред
        ([5, 4, 3, 2, 1], [5]),  # Намаляваща редица
        ([0, 1, 2, 3], [0, 1, 2, 3]),  # Включително нула
        ([-5, -1, -3], []),  # Всички отрицателни
        ([1, 1, 1, 1], [1, 1, 1, 1]),  # Равни стойности
        ([-1, -1, -1, 0, 1, 2, -1, -2, -3, 4, 5, 1, 2, 3, 6], [0, 1, 2, 4, 5, 6]),
        ([], []),  # Празен списък
    ]

    for i, (inp, expected) in enumerate(tests, 1):
        head = list_to_linked(inp)
        result = positiveStalinSort(head)
        out = linked_to_list(result)
        print(f"Тест {i}: вход={inp} → изход={out} | очаквано={expected}")
        assert out == expected, f"Грешка при тест {i}"


# Стартиране на тестовете
if __name__ == "__main__":
    test_positiveStalinSort()
    print("Всички тестове преминаха успешно.")

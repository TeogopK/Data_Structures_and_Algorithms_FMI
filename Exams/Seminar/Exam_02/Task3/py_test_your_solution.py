# ===============================
# Задача 3 (50т) - Тестове
# ===============================

from typing import Optional


class Node:
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next_node = next_node


def partition(lst: Optional[Node], x: int) -> Optional[Node]:
    """Напиши твоето решение тук!"""
    if not lst:
        return None

    before_head = Node(0)
    after_head = Node(0)
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

    after.next_node = None
    before.next_node = after_head.next_node
    return before_head.next_node


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


def test_partition():
    tests = [
        # Примерни тестове от условието
        (([2, 7, 3, 4, 9, 1, 8], 6), [2, 3, 4, 1, 7, 9, 8]),
        (([-3, 8, 9, 2, 7, 5, 8], 7), [-3, 2, 5, 8, 9, 7, 8]),
        # Допълнителни тестове
        (([1, 4, 3, 2, 5, 2], 3), [1, 2, 2, 4, 3, 5]),
        (([1, 4, 2, 10, 3], 10), [1, 4, 2, 3, 10]),
        (([10, 9, 8, 7, 6, 5], 7), [6, 5, 10, 9, 8, 7]),
        (([1, 2, 3, 4, 5], 0), [1, 2, 3, 4, 5]),
        (([1, 2, 3, 4, 5], 10), [1, 2, 3, 4, 5]),
        (([7, 7, 7, 7], 7), [7, 7, 7, 7]),
        (([], 5), []),  # Празен списък
        (([-5, -2, -3, 0, 1, 2], 0), [-5, -2, -3, 0, 1, 2]),
    ]

    for i, ((inp, x), expected) in enumerate(tests, 1):
        head = list_to_linked(inp)
        result = partition(head, x)
        out = linked_to_list(result)
        print(f"Тест {i}: вход={inp}, x={x} → изход={out} | очаквано={expected}")
        assert sorted(out[: len([v for v in out if v < x])]) == sorted(
            [v for v in inp if v < x]
        ), f"Грешка при тест {i}: групата < x не е коректна"
        assert sorted(out[len([v for v in out if v < x]) :]) == sorted(
            [v for v in inp if v >= x]
        ), f"Грешка при тест {i}: групата ≥ x не е коректна"


# Стартиране на тестовете
if __name__ == "__main__":
    test_partition()
    print("Всички тестове преминаха успешно.")

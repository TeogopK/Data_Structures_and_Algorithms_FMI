# Контролно 2 СДА 2026/27, Вариант 2, Задача 2 - filterRocksSortDesc

# O(N + M) time complexity, where N and M are the lengths of the two lists
# O(N + M) space complexity - for the recursion stack (we still reuse the nodes)
# Note: Python's default recursion limit (~1000) makes this fail on long lists


class ListNode:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def skip_rocks(node):
    # Skips the rock (zero) nodes at the front of the list
    # and returns the first normal node (or None)
    while node and node.value == 0:
        node = node.next

    return node


def filterRocksSortDesc(first, second):
    first = skip_rocks(first)
    second = skip_rocks(second)

    if not first and not second:
        return None

    # Take the bigger head (or the only one left) and merge the rest after it.
    # When one list is over we keep recursing on the other, so its rocks are removed too
    if not second or (first and first.value >= second.value):
        first.next = filterRocksSortDesc(first.next, second)
        return first

    second.next = filterRocksSortDesc(first, second.next)
    return second

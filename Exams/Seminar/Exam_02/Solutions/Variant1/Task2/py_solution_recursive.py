# Контролно 2 СДА 2026/27, Вариант 1, Задача 2 - noiseFilterMerge

# O(N + M) time complexity, where N and M are the lengths of the two lists
# O(N + M) space complexity - for the recursion stack (we still reuse the nodes)
# Note: Python's default recursion limit (~1000) makes this fail on long lists


class ListNode:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next


def skip_noise(node):
    # Skips the noise (negative) nodes at the front of the list
    # and returns the first normal node (or None)
    while node and node.value < 0:
        node = node.next

    return node


def noiseFilterMerge(first, second):
    first = skip_noise(first)
    second = skip_noise(second)

    if not first and not second:
        return None

    # Take the smaller head (or the only one left) and merge the rest after it.
    # When one list is over we keep recursing on the other, so its noise is removed too
    if not second or (first and first.value <= second.value):
        first.next = noiseFilterMerge(first.next, second)
        return first

    second.next = noiseFilterMerge(first, second.next)
    return second

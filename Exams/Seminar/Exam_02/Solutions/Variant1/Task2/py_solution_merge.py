# Контролно 2 СДА 2026/27, Вариант 1, Задача 2 - noiseFilterMerge

# O(N + M) time complexity, where N and M are the lengths of the two lists
# O(1) additional space complexity - we reuse the nodes of the input lists


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
    # Dummy node, so we don't need a special case for the head of the result
    dummy = ListNode(0)
    tail = dummy

    first = skip_noise(first)
    second = skip_noise(second)

    # Classic merge of two sorted lists - the only difference is that
    # after taking a node we skip the noise right after it
    while first and second:
        if first.value <= second.value:
            tail.next = first
            first = skip_noise(first.next)
        else:
            tail.next = second
            second = skip_noise(second.next)

        tail = tail.next

    # The rest of the remaining list can still contain noise, so we can't just attach it
    rest = first if first else second
    while rest:
        tail.next = rest
        tail = rest
        rest = skip_noise(rest.next)

    # The last taken node may still point to a noise node
    tail.next = None

    return dummy.next

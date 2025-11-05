def process_backspace(s):
    stack_ = []

    for c in s:
        if c != "#":
            stack_.append(c)
        elif len(stack_):
            stack_.pop()

    return stack_


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # O(len(s) + len(t))
        return process_backspace(s) == process_backspace(t)

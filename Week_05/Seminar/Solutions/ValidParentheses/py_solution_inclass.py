class Solution:
    def isValid(self, s: str) -> bool:
        opening = "([{"
        closing = ")]}"

        stack_ = []

        for c in s:
            if c in opening:
                stack_.append(c)
            else:
                if not stack_ or opening[closing.index(c)] != stack_[-1]:
                    return False
                else:
                    stack_.pop()

        return not stack_

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        opening = '([{'
        closing = ')]}'

        for c in s:
            if c in opening:
                stack.append(c)
            elif c in closing:
                if len(stack) == 0 or closing.index(c) != opening.index(stack[-1]):
                    return False
                else:
                    stack.pop()

        return True if not len(stack) else False
            
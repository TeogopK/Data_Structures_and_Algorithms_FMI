from collections import deque

class Solution:
    def fill_stack(self, text):
        stack = deque()

        for el in text:
            if el != '#':
                stack.append(el)
            elif stack: # len(stack) != 0
                stack.pop()             
            
        return stack

    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack = self.fill_stack(s)
        t_stack = self.fill_stack(t)

        return s_stack == t_stack
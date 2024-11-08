# https://leetcode.com/problems/backspace-string-compare

class Stack:
    def __init__(self):
        self.items = deque()

    def push(self, el):
        self.items.appendleft(el)

    def empty(self):
        return len(self.items) == 0

    def pop(self):
        el = self.items[0]
        self.items.popleft()
        return el

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack = Stack()
        for c in s:
            if c != "#":
                s_stack.push(c)
            elif not s_stack.empty():
                s_stack.pop()
        t_stack = Stack()
        for c in t:
            if c != "#":
                t_stack.push(c)
            elif not t_stack.empty():
                t_stack.pop()
        while not s_stack.empty() and not t_stack.empty():
            if s_stack.pop() != t_stack.pop():
                return False
        return s_stack.empty() and t_stack.empty()

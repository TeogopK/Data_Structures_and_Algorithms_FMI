# https://leetcode.com/problems/valid-parentheses

from collections import deque

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
    def isValid(self, s: str) -> bool:
        stack = Stack()
        for c in s:
            if c in {'(', '{', '['}:
                stack.push(c)
            else:
                if stack.empty():
                    return False
                last = stack.pop()
                if not ((last == '{' and c == '}') or (last == '(' and c == ')') or (last == '[' and c == ']')):
                    return False
        return stack.empty()

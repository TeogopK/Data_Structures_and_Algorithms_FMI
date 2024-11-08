# https://leetcode.com/problems/backspace-string-compare

from collections import deque

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_stack = deque()
        for c in s:
            if c != "#":
                s_stack.appendleft(c)
            elif len(s_stack) > 0:
                s_stack.popleft()
        t_stack = deque()
        for c in t:
            if c != "#":
                t_stack.appendleft(c)
            elif len(t_stack) > 0:
                t_stack.popleft()
        return s_stack == t_stack

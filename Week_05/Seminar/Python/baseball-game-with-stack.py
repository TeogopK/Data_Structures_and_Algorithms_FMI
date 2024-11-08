# https://leetcode.com/problems/baseball-game

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
    def calPoints(self, operations: List[str]) -> int:
        scores = Stack()
        for op in operations:
            if op == "+":
                prev1 = scores.pop()
                prev2 = scores.pop()
                scores.push(prev2)
                scores.push(prev1)
                scores.push(prev1+prev2)
            elif op == "D":
                prev = scores.pop()
                scores.push(prev)
                scores.push(prev*2)
            elif op == "C":
                scores.pop()
            else:
                scores.push(int(op))
        result = 0
        while not scores.empty():
            result += scores.pop()
        return result

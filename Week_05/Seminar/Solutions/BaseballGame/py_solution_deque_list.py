from collections import deque

class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stack = deque() # works with list as well: stack = []

        for op in operations:
            new_score = 0

            if op == 'C':
                stack.pop()
                continue
            elif op == 'D':
                new_score = stack[-1] * 2
            elif op == '+':
                new_score = stack[-1] + stack[-2]
            else:
                new_score = int(op)
            
            stack.append(new_score)
        
        return sum(stack)

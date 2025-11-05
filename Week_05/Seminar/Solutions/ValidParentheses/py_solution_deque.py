from collections import deque

class Solution:
    def isValid(self, s: str) -> bool:
        d = deque()

        for el in s:
            if el not in [']', '}', ')']:
                d.append(el)
            else:
                if len(d) == 0:
                    return False
                if el == '}' and d.pop() != '{':
                    return False
                if el == ')' and d.pop() != '(':
                    return False
                if el == ']' and d.pop() != '[':
                    return False
    
        return len(d) == 0

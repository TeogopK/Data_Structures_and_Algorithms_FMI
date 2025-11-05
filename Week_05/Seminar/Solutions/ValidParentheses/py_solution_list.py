"""
List append() and pop() are O(1) in Python.
https://wiki.python.org/moin/TimeComplexity
"""

class Solution:
    def isValid(self, s: str) -> bool:
        d = []

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


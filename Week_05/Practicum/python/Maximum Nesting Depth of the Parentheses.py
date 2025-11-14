class Solution:
    def maxDepth(self, s: str) -> int:
        stack_ = []

        ans = 0
        
        for c in s:
            if c == '(':
                stack_.append(1)
                ans = max(ans, len(stack_))
            elif c == ')':
                stack_.pop()

        return ans
# https://leetcode.com/problems/baseball-game

class Solution:
    def calPoints(self, operations: List[str]) -> int:
        scores = []
        for op in operations:
            if op == "+":
                scores.append(scores[-1] + scores[-2])
            elif op == "D":
                scores.append(scores[-1] * 2)
            elif op == "C":
                scores.pop()
            else:
                scores.append(int(op))
        return sum(scores)

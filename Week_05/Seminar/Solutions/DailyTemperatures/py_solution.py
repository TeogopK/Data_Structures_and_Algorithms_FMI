class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s = []
        output = [0] * len(temperatures)

        for i, x in enumerate(temperatures):

            while len(s) != 0 and s[-1][1] < x:
                j, _ = s.pop()
                output[j] = i - j

            s.append((i, x))

        return output

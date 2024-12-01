class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        d = dict()
        counter = 1
        for i, num in enumerate(nums):
            if num == x:
                d[counter] = i
                counter += 1

        ans = []

        for query in queries:
            if query in d.keys():
                ans.append(d[query])
            else:
                ans.append(-1)

        return ans
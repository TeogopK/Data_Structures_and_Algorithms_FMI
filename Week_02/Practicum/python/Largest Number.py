def compare(a, b):
    if a + b > b + a: return -1
    if a + b < b + a: return 1
    return 0

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        ans = "".join(sorted(map(str, nums), key=cmp_to_key(compare)))

        # return str(int(ans))

        i = 0
        while i < len(ans) and ans[i] == '0':
            i += 1

        if i == len(ans):
            return '0'
        
        return ans[i:]
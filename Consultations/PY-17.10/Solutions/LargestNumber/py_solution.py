def compare(a, b):
    if a + b > b + a:
        return -1
    if a + b < b + a:
        return 1
    return 0


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        arr_str = map(str, nums)
        arr_str_sorted = sorted(arr_str, key=cmp_to_key(compare))  # [str(x) for x in nums]

        ans = "".join(arr_str_sorted)
        ans = str(int(ans))
        return ans

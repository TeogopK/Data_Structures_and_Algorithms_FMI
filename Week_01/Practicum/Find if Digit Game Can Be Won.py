class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        one_sum, two_sum = 0, 0

        for num in nums:
            if len(str(num)) == 1:
                one_sum += num
            else:
                two_sum += num

        return one_sum != two_sum
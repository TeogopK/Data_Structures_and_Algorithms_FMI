class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]: 
        count_lst = [0 for _ in range(max(nums) + 1)]

        for num in nums:
            count_lst[num] += 1

        matrix = []

        for _ in range(max(count_lst)):
            row = []

            for i in range(len(count_lst)):
                if count_lst[i] != 0:
                    row.append(i)
                    count_lst[i] -= 1

            matrix.append(row)

        return matrix
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = set()

        zeros = [num for num in nums if num == 0]

        if len(zeros) >= 3:
            ans.add(tuple([0, 0, 0]))

        has_zero = True if len(zeros) else False

        pos_list = [num for num in nums if num > 0]
        neg_list = [num for num in nums if num < 0]

        pos_set = set(pos_list)
        neg_set = set(neg_list)
    
        if has_zero:
            for neg_num in neg_set:
                if -1 * neg_num in pos_set:
                    ans.add(tuple([neg_num, -1 * neg_num, 0]))

        for i in range(len(neg_list) - 1):
            for j in range(i + 1, len(neg_list)):
                target = -1 * (neg_list[i] + neg_list[j])

                if target in pos_set:
                    ans.add(
                        tuple(sorted([neg_list[i], neg_list[j], target]))
                    )

        for i in range(len(pos_list) - 1):
            for j in range(i + 1, len(pos_list)):
                target = -1 * (pos_list[i] + pos_list[j])
                
                if target in neg_set:
                    ans.add(
                        tuple(sorted([pos_list[i], pos_list[j], target]))
                    )

        return list(ans)
                    
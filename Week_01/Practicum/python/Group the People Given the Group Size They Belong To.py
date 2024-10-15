class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        
        count_lst = [[] for _ in range(501)]

        for i, num in enumerate(groupSizes):
            count_lst[num].append(i)
        
        groups = []

        for idx, group_lst in enumerate(count_lst):
            if len(group_lst) == 0:
                continue

            groups_count = int(len(group_lst) / idx)
            group_idx = 0
            for group in range(groups_count):
                current_group = []
                for _ in range(idx):
                    current_group.append(group_lst[group_idx])
                    group_idx += 1

                groups.append(current_group)

        return groups
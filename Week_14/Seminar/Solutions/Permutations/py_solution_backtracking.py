class Solution:
    def dfs(self, path, all_paths, nums, used):
        if len(path) == len(nums):
            all_paths.append(path.copy())
            return all_paths

        for num in nums:
            if num in used:
                continue
            path.append(num)
            used.add(num)

            self.dfs(path, all_paths, nums, used)
        
            path.pop()
            used.remove(num)

        return all_paths

    def permute(self, nums: List[int]) -> List[List[int]]:
        all_paths = []
        path = []
        used = set()

        return self.dfs(path, all_paths, nums, used)

# Loops through the list and adds each elements index in a dictionary.
# Then, checks if the potential partner was seen via the dictionary.
# Finally, gets the index of the partner through the dictionary.

# Note: We still have not learned about dicts!


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_nums = {}  # Saves on which position each num was seen.

        for i in range(len(nums)):
            friend = target - nums[i]

            if friend in seen_nums:
                return [seen_nums[friend], i]

            seen_nums[nums[i]] = i

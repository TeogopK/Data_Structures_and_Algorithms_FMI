def binary_search(chars, target):
    left, right = 0, len(chars) - 1

    while left <= right:
        mid = (left + right) // 2
        
        if chars[mid] > target:
            right = mid - 1
        else:
            left = mid + 1

    return mid


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        idx = binary_search(letters, target)
        if letters[idx] == target or letters[idx] < target:
            return letters[(idx + 1) % len(letters)]
        return letters[idx]
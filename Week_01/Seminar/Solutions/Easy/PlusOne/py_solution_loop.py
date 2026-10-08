# Adds one to the last digit.
# If last digit was not 9, stops.
# Else - "increments" each digit starting from the end of the list.

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += 1
            digits[i] %= 10

            if digits[i] != 0:
                return digits

        # variation: return [1] + digits
        digits.insert(0, 1) 

        return digits 
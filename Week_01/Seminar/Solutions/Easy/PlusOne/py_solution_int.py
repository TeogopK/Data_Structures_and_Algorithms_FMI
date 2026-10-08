# Creates the number as an integer (Bigint).
# Adds one.
# Creates the list from the number.

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0

        for digit in digits:
            num = num * 10 + digit

        num += 1

        return [int(digit) for digit in str(num)] 
        # variation: return list(map(int, str(num)))
    
    
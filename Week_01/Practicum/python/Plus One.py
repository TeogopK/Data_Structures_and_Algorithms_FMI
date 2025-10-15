class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        increment = 1
        carry = 0
        for i in range(len(digits) - 1, -1, -1):
            new_digit = (digits[i] + increment + carry) % 10
            carry = (digits[i] + increment + carry) // 10
            digits[i] = new_digit
            increment = 0 # Increment only the last digit

        if carry:
            return [1] + digits
        return digits
        
        # One-liner solution
        # return list(map(int, list(str(int("".join(map(str, digits))) + 1))))
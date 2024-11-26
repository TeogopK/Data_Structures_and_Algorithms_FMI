"""
Solution using 'Rolling hash'. 
https://cp-algorithms.com/string/string-hashing.html
"""
from collections import defaultdict

class Solution:
    def encode_character(self, ch):
        """Converts a character into integer number."""
        if ch == 'A': return 0
        if ch == 'C': return 1
        if ch == 'G': return 2
        return 3

    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        # Trivial case
        if len(s) < 10:
            return []

        # Counts the strings with equal hash
        d = defaultdict(int)

        # Saves every string that was seen more than once
        result = []

        # Initial hash value
        hash_value = 0

        # Calculates the hash value of the first 9 characters
        # Note that we need only the strings with size 10.
        for i in range(9):
            hash_value = hash_value * 4 + self.encode_character(s[i])

        # Saves the multiplier of the first character as constant (the largest one)
        first_pow = 4 ** 9

        # Iterates through all possible 10 characters strings
        for i in range(9, len(s)):

            # Calculates the current hash value and increases the count in the dictionary
            hash_value = hash_value * 4 + self.encode_character(s[i])
            d[hash_value] += 1

            # Saves the string if it has occurred more than once
            if d[hash_value] == 2:
                result.append(s[i-9:i+1])

            # Removes the earliest character from the hash value
            hash_value -= first_pow * self.encode_character(s[i-9])

        return result
            
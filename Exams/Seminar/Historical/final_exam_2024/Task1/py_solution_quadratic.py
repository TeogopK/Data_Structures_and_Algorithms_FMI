"""
Solution idea:
    Skip each letter in the string once.
    Check if the count of each remaining letter 
        in the string is the same.
"""
from collections import defaultdict

def solve(word):
    for i in range(len(word)):
        chars = defaultdict(int)
        
        for j, ch in enumerate(word):
            if i == j:
                continue
            chars[ch] += 1
            
        if len(set(chars.values())) == 1:
            return True
        
    return False       
    

N = int(input())
words = [input() for _ in range(N)]

for word in words:
    output = 1 if solve(word) else 0
    print(output)

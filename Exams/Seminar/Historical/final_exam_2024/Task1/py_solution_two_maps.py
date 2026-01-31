from collections import defaultdict

def solve(word):
    chars = defaultdict(int) # letter -> count in string
    for ch in word:
        chars[ch] += 1

    if len(chars) == 1: # aaaaa
        return True
    
    frequencies = defaultdict(int) # counts of letters -> frequency of the count
    for count in chars.values():
        frequencies[count] += 1

    if len(frequencies) != 2:  # abbccc/ abcd
        return False
    
    by_frequency = list(sorted(frequencies.items(), key = lambda x: (x[1], -x[0]))) # sort by smallest frequency
    count_key_removable, frequency_removable = by_frequency[0]
    count_key_unchanged, frequency_unchanged = by_frequency[1]
    
    if frequency_removable != 1: # aaabbbccdd
        return False
    
    if count_key_removable == 1: # xaabbcc
        return True
    
    if count_key_unchanged == 1 and frequency_unchanged == 1: # aaaax
        return True
    
    if count_key_removable - 1 == count_key_unchanged: # xxxxaaabbbccc
        return True

    return False # xxxxxaaabbbccc

N = int(input())
words = [input() for _ in range(N)]

for word in words:
    output = 1 if solve(word) else 0
    print(output)

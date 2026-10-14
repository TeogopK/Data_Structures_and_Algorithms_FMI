ASCII_SIZE = 256

input()
line = input()

slots = ASCII_SIZE * [0]

for ch in line:
    slots[ord(ch)] += 1

digits = "".join(chr(i) * slots[i] for i in range(ASCII_SIZE) if chr(i).isdigit())
lowers = "".join(chr(i) * slots[i] for i in range(ASCII_SIZE) if chr(i).islower())
uppers = "".join(chr(i) * slots[i] for i in range(ASCII_SIZE) if chr(i).isupper())

sorted_line = digits + lowers + uppers

print(sorted_line)

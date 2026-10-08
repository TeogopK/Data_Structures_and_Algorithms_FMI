N = int(input())
line = input()
number_strings = line.split(" ")
arr = []

for x in number_strings:  # Slowest variant using python for loops
    arr.append(int(x))

summ = 0

for y in arr:
    summ += y

print(summ)

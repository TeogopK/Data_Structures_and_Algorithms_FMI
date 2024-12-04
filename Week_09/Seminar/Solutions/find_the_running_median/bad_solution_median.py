from statistics import median

arr = []
for i in range(int(input())):
    arr.append(int(input()))
    print("{:.1f}".format(median(arr)))
    
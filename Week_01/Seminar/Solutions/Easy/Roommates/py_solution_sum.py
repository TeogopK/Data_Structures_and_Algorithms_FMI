# https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410
for _ in range(int(input())):
    length, arr = input().split()
    
    count = sum(1 for i in range(int(length) - 1) if arr[i] == arr[i + 1])
            
    print(count)
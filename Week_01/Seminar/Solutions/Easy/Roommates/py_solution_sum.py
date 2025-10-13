for _ in range(int(input())):
    length, arr = input().split()
    
    count = sum(1 for i in range(int(length) - 1) if arr[i] == arr[i + 1])
            
    print(count)
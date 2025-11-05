"""Main idea is looping through the input from the back"""
N = int(input())
arr = [int(el) for el in input().split()]

stack = []
max_length = 0
best_indx = N - 1

for i in reversed(range(N)):
    while stack and arr[i] >= stack[-1]:
        stack.pop()
        
    stack.append(arr[i])
    
    if len(stack) >= max_length:
        max_length = len(stack)
        best_indx = i
        
print(best_indx)
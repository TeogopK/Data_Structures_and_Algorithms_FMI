N = int(input())
arr = [int(x) for x in input().split()]

ans, ans_i = 0, -1
mono_stack = []

for i, height in enumerate(reversed(arr)):
    while mono_stack and height >= mono_stack[-1]:
        mono_stack.pop()
    
    mono_stack.append(height)
    # print(mono_stack)
    if len(mono_stack) >= ans:
        ans = len(mono_stack)
        ans_i = i
        
print(len(arr) - ans_i - 1)
    
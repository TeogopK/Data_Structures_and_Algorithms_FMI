from collections import defaultdict

def get_input():
    """This function bypasses the wrong input format.
    Note that the real exam will not have such issues."""
    N = int(input())
    all_stickers = list(map(int, input().split()))
    all_wanted = []
    
    try:
        all_wanted = list(map(int, input().split()))
    except:
        all_wanted = all_stickers[N:]
        all_stickers = all_stickers[:N]
    
    return N, all_stickers, all_wanted

N, all_stickers, all_wanted = get_input()

current_stickers = defaultdict(int)
total = 0

for day in range(N):
    added = all_stickers[day]
    current_stickers[added] += 1
    
    wanted = all_wanted[day]
    if current_stickers[wanted] == 0:
        total += 1
    else:
        current_stickers[wanted] -= 1
    
print(total)
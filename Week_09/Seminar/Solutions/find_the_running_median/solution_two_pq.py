"""To achieve a Max Heap, numbers are inserted in negative form"""
from queue import PriorityQueue

def get_average(below, above):
    if below.qsize() > above.qsize():
        return -below.queue[0]
    elif below.qsize() < above.qsize():
        return above.queue[0]
    return (-below.queue[0] + above.queue[0]) / 2

def rebase(below, above):
    if below.qsize() > above.qsize() + 1:
        above.put(-below.get())
    elif above.qsize() > below.qsize() + 1:
        below.put(-above.get())

N = int(input())
arr = [int(input()) for _ in range(N)]

above = PriorityQueue()
below = PriorityQueue() # max heap

average = 0

for el in arr:
    if el <= average:
        below.put(-el)
    else:
        above.put(el)
        
    rebase(below, above)
    
    average = get_average(below, above)
    print(f"{average:.1f}")

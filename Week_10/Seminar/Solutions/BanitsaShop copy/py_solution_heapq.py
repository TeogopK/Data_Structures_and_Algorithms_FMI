from heapq import heappush, heappop

N = int(input())

tasks = [] # by start, duration, index
for i in range(N):
    start, duration = map(int, input().split())
    
    heappush(tasks, (start, duration, i))
    
waiting = [] # by duration and index

# Add the earliest task
time = tasks[0][0]
heappush(waiting, heappop(tasks)[1::])

while waiting:
    duration, index = heappop(waiting)
    time += duration
    
    print(index, end=' ')
    
    # Add the tasks that can be started while the one is being done
    while tasks and tasks[0][0] <= time:
        heappush(waiting, heappop(tasks)[1::])
        
    # If there are no tasks waiting fast forward the time
    if not waiting and tasks:
        time = tasks[0][0]
        heappush(waiting, heappop(tasks)[1::])
    
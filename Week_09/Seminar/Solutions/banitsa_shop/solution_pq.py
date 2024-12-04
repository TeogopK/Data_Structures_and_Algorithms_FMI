from queue import PriorityQueue

N = int(input())

tasks = PriorityQueue() # by start, duration, index
for i in range(N):
    start, duration = map(int, input().split())
    
    tasks.put((start, duration, i))
    
waiting = PriorityQueue() # by duration and index

# Add the earliest tasks
time = tasks.queue[0][0]
waiting.put(tasks.get()[1::])

while not waiting.empty():
    duration, index = waiting.get()
    time += duration
    
    print(index, end=' ')
    
    # Add the tasks that can be started while the one is being done
    while not tasks.empty() and tasks.queue[0][0] <= time:
        waiting.put(tasks.get()[1::])
        
    # If there are no tasks waiting fast forward the time
    if waiting.empty() and not tasks.empty():
        time = tasks.queue[0][0]
        waiting.put(tasks.get()[1::])
    
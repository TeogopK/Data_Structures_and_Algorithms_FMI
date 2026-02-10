"""
Commands is a heap of all commands sorted by time and lexicographically by command,
    since we want "ADD" before "CANCEL" if they have the same time.
    Example element (0, "ADD", 1, 4, 5)

Waiting_pq is a heap of all waiting tasks sorted by highest priority and lowest time comes first.
    Example element (-5, 0, 1, 4) for the above command.

Waiting_set is a set of all waiting tasks by their `iid` for O(1) searching and a source of truth.
    It will allow us to do lazy removal.
    Example state of the set: {1} for the above command.

Inprogress_pq is a heap of all tasks in progress sorted by the time they will end.
    Example element 4 for the above command if it started at time 0.
"""

from heapq import heappush, heappop


def get_input():
    """
    Gets the input as tuple (t, command_name, id, d, p)
        since we want sorted by time and "added" before "cancel".
    Example (0, "ADD", 1, 4, 5)
    """
    S, E = map(int, input().split())

    commands = []
    for _ in range(E):
        line_args = input().split()
        command_string = line_args[0]
        other_args = [int(arg) for arg in line_args[1:]]

        other_args.insert(1, command_string)
        heappush(commands, tuple(other_args))

    return commands, S, E


def add_waiting(waiting_pq, waiting_set, command):
    """
    Adds a waiting task by highest priority and lowest time comes sortes.
    'iid' and 'd' do not matter for the sorting.

    We keep a set of addded tasks to have O(1) searching and a source of truth.
    Removed tasks can be in the pq but if not said in the set they are to be skipped - lazy removal.
    """
    t, _, iid, d, p = command
    heappush(waiting_pq, (-p, t, iid, d))
    waiting_set.add(iid)


def remove_waiting_by_iid(waiting_set, command):
    """
    Removes a task just by removing the reference from the source of truth - the set.
    If the `iid` is -1 skip as said in the task statement.

    Note that:
        Removing from the heap will break the heap property!
        This should not be done: waiting_pq.pop(index_of_iid)
    """
    iid = command[2]
    if iid == -1:
        return

    if iid in waiting_set:
        waiting_set.remove(iid)


def clean_waiting_pq_from_cancelled(waiting_pq, waiting_set):
    """
    Removes all illegal elements on the top of the pq
        that are not mentioned in the source of truth - the set.
    This should be done always before checking the actual len of the pq or removing an element.
    """
    while len(waiting_pq) > 0:
        iid = waiting_pq[0][2]

        if iid in waiting_set:
            break

        heappop(waiting_pq)


def get_from_waiting(waiting_pq, waiting_set):
    """
    Pops the first element in the waiting pq, ignoring any that are not referenced
        by the source of truth - the set.
    Updates the set as well.
    """
    clean_waiting_pq_from_cancelled(waiting_pq, waiting_set)
    p, _, iid, d = heappop(waiting_pq)
    p = -p

    waiting_set.remove(iid)

    return p, d, iid


def choose_time(commands, inprogress_pq):
    """
    Chooses the time to skip forward to.
    Note that we can not always jump to when the server ends a task and can get a new one.
    Since we can have 1 idle server and 1 working,
        skipping to when the first is not idle will miss a potential new task.
    """
    INF = float("inf")
    next_cmd = commands[0][0] if commands else INF
    next_done = inprogress_pq[0] if inprogress_pq else INF

    t = min(next_cmd, next_done)
    return None if t == INF else t


commands, S, E = get_input()

time_now = 0
answers = []

waiting_pq = []
waiting_set = set()
inprogress_pq = []


# We stop when we have finished all commands coming and all tasks have been accepted by the server and then completed
while True:
    # Remove finished tasks
    while len(inprogress_pq) > 0 and inprogress_pq[0] <= time_now:
        heappop(inprogress_pq)

    # Add all commands that come at the same time. Commands with "ADD" must be before "CANCEL".
    while len(commands) > 0 and commands[0][0] <= time_now:
        command = heappop(commands)

        if command[1] == "ADD":
            add_waiting(waiting_pq, waiting_set, command)
        if command[1] == "CANCEL":
            remove_waiting_by_iid(waiting_set, command)

    # Add tasks than can start if there is capacity
    while len(inprogress_pq) < S:
        # When there are no waiting tasks (and there is capacity)
        if len(waiting_set) == 0:
            # We can add a smart time travel to new commands here
            break

        _, d, iid = get_from_waiting(waiting_pq, waiting_set)

        heappush(inprogress_pq, d + time_now)
        answers.append(iid)

    time_now = choose_time(commands, inprogress_pq)
    if time_now is None:
        break

print(*answers)

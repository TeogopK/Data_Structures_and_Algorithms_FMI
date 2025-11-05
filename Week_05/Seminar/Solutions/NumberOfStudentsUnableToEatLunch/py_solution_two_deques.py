from collections import deque

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        queue = deque(students)
        sandwiches = deque(sandwiches)

        count_denied = 0
        while len(queue) > count_denied:
            if queue[0] == sandwiches[0]:
                sandwiches.popleft()
                count_denied = 0
            else:
                queue.append(queue[0])
                count_denied += 1

            queue.popleft()

        return count_denied
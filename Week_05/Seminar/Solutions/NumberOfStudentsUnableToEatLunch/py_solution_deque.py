from collections import deque

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        q = deque(students)

        for s in sandwiches:
            i, old_size = 0, len(q)

            while q[0] != s:
                q.append(q.popleft())
                i += 1

                if i == old_size:
                    return i

            q.popleft()
        
        return 0      
            
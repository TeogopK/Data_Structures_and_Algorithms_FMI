class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        students = deque(students)
        sandwiches = list(reversed(sandwiches))

        count_ = 0

        while len(students) and count_ < len(students):
            student = students.popleft()
            if student == sandwiches[-1]:
                sandwiches.pop()
                count_ = 0
            else:
                students.append(student)
                count_ += 1

        return len(students)
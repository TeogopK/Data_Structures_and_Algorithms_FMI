"""List method pop(0) is O(N)"""
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count_denied = 0
        while len(students) > count_denied:
            if students[0] == sandwiches[0]:
                sandwiches.pop(0)
                count_denied = 0
            else:
                students.append(students[0])
                count_denied += 1

            students.pop(0)

        return count_denied
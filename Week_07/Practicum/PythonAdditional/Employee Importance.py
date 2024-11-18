"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

def dfs(employee_by_id, employee):
    if employee is None:
        return 0

    total_importance = employee.importance

    for subordinate in employee.subordinates:
        total_importance += dfs(employee_by_id, employee_by_id[subordinate])

    return total_importance

class Solution:
    def getImportance(self, employees: List['Employee'], id_: int) -> int:
        employee_by_id = [None for _ in range(2001)]
        for employee in employees:
            employee_by_id[employee.id] = employee

        return dfs(employee_by_id, employee_by_id[id_])
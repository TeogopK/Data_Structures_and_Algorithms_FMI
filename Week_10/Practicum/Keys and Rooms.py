def dfs(rooms, visited, current):
    if visited[current]:
        return

    visited[current] = True

    for neighb in rooms[current]:
        dfs(rooms, visited, neighb)


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [False for _ in rooms]
        
        dfs(rooms, visited, 0)

        return sum(visited) == len(rooms)


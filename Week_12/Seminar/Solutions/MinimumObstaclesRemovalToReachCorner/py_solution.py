class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # min_remove[i][j] stores the minimum obstacles removed to reach (i,j)
        min_remove = [[float("inf")] * n for _ in range(m)]
        min_remove[0][0] = grid[0][0]

        # priority queue: (total_obstacles_removed, x, y)
        heap = [(grid[0][0], 0, 0)]

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        while heap:
            obstacles, x, y = heapq.heappop(heap)

            # if we reached the target
            if x == m - 1 and y == n - 1:
                return obstacles

            # if we have already found a better path to (x,y), skip
            if obstacles > min_remove[x][y]:
                continue

            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_obstacles = obstacles + grid[nx][ny]
                    if new_obstacles < min_remove[nx][ny]:
                        min_remove[nx][ny] = new_obstacles
                        heapq.heappush(heap, (new_obstacles, nx, ny))

        return min_remove[m - 1][n - 1]

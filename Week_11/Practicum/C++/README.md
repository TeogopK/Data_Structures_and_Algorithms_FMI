
## BFS в матрица

```c++
// Схема за bfs в матрица

int start, end; // начални координати в матрицата
int bfs(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>>directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}}; // това е ако може да се движим само в 4 съседни клетки
    queue<pair<int, int>>q;
    vector<vector<bool>>visited(rows, vector<bool>(cols, false)); // ако е възможно може да модифицираме входната матрица
    visited[start][end] = true;
    q.push({start, end}); // ако е multisource bfs задачата тук в опашката вкарваме всички начални позиции, като се ъпдейтва и visited съответно
    int level = 0;
    while (!q.empty()) {
        size_t currentSize = q.size();
        for (auto i = 0; i < currentSize; i++) {
            int currentI = q.front().first;
            int currentJ = q.front().second;
            if (condition) return level; // намери ли сме целевата клетка
            q.pop();
            for (const auto& direction : directions) {
                int newI = currentI + direction[0];
                int newJ = currentJ + direction[1];
                if ( newI >= 0 && newI < rows && newJ >= 0 && newJ < cols && !visited[newI][newJ] && condition) {
                    visited[newI][newJ] = true;
                    q.push({newI, newJ});
                }
            }
        }
        level++;
    }
}
```

### Medium

- [**Rotting Oranges**](https://leetcode.com/problems/rotting-oranges/description/)
- [**Shortest Path In Binary Matrix**](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)
- [**Nearest Exit From Entrance In Maze**](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)
- [**Minimum Knight Moves**](https://leetcode.com/problems/minimum-knight-moves/description/)


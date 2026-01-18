#include <bits/stdc++.h>
using namespace std;

int n, m;
int cell;
int unimmunizedCells = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cell;
			if (cell == 0) {
				unimmunizedCells++;
			}
			if (cell == 2) {
				q.push({ i, j }); // q.emplace(i, j);
			}
			grid[i][j] = cell;
		}
	}

	int time = 0;
	while (!q.empty()) {

		if (!unimmunizedCells) {
			cout << time;
			return 0;
		}

		size_t size = q.size();
		for (int i = 0; i < size; i++) {
			auto currentCell = q.front();
			q.pop();
			for (const auto& direction : directions) {
				int dx = currentCell.first + direction.first;
				int dy = currentCell.second + direction.second;
				if (dx >= 0 && dx < n && dy >= 0 && dy < m && !grid[dx][dy]) {
					q.push({ dx, dy });
					grid[dx][dy] = 2;
					unimmunizedCells--;
				}
			}
		}
		time++;
	}

	cout << (unimmunizedCells > 0 ? -1 : time);

	return 0;
}
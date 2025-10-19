#include <iostream>
#include <vector>

bool isValid(const std::pair<int, int>& pos, int rows, int cols) {
	return pos.first >= 0 && pos.first < cols
		&& pos.second >= 0 && pos.second < rows;
}

bool existsPath(std::vector<std::vector<int>>& matrix, const std::pair<int, int>& start, const std::pair<int, int>& end) {
	if (!isValid(start, matrix.size(), matrix[0].size())) {
		return false;
	}

	if (matrix[start.first][start.second] == 1 || matrix[start.first][start.second] == 2) {
		return false;
	}

	if (start.first == end.first && start.second == end.second) {
		return true;
	}

	matrix[start.first][start.second] = 2;
	bool result = existsPath(matrix, { start.first - 1, start.second }, end)
		|| existsPath(matrix, { start.first + 1, start.second }, end)
		|| existsPath(matrix, { start.first, start.second - 1 }, end)
		|| existsPath(matrix, { start.first, start.second + 1 }, end);
		

	if (!result) {
		matrix[start.first][start.second] = 0;
	}

	return result;
}

int main() {
	size_t n;
	std::cin >> n;
}

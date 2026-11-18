// Контролно 3 СДА 2026/27, Задача 2 - отрицателните по нива (BFS, вход от конзолата)

// O(N) time complexity
// O(N) space complexity

#include <iostream>
#include <queue>
#include <vector>

// tree[i] holds the children of node i
void printNegativesByLevel(const std::vector<int>& values, const std::vector<std::vector<int>>& tree) {
	std::queue<int> q;
	q.push(0);
	int level = 0;

	while (!q.empty()) {
		bool hasNegatives = false;

		// process exactly the nodes of the current level
		size_t levelSize = q.size();
		for (size_t i = 0; i < levelSize; i++) {
			int node = q.front();
			q.pop();

			if (values[node] < 0) {
				// print the level header only before the first negative value
				if (!hasNegatives) {
					std::cout << "Ниво " << level << ":";
					hasNegatives = true;
				}
				std::cout << " " << values[node];
			}

			for (int child : tree[node]) {
				q.push(child);
			}
		}

		if (hasNegatives) {
			std::cout << "\n";
		}

		level++;
	}
}

int main() {
	int n, e;
	std::cin >> n >> e;

	std::vector<int> values(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i];
	}

	std::vector<std::vector<int>> tree(n);
	for (int i = 0; i < e; i++) {
		int parent, child;
		std::cin >> parent >> child;
		tree[parent].push_back(child);
	}

	printNegativesByLevel(values, tree);
}

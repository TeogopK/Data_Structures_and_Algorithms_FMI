// Контролно 3 СДА 2026/27, Задача 2 - отрицателните по нива (BFS, вход от конзолата)

// O(N) time complexity
// O(N) space complexity

#include <iostream>
#include <queue>
#include <vector>

struct Node {
	int value;
	std::vector<Node*> children;

	Node(int value) : value(value) {}
};

void printNegativesByLevel(Node* root) {
	std::queue<Node*> q;
	q.push(root);
	int level = 0;

	while (!q.empty()) {
		bool hasNegatives = false;

		// process exactly the nodes of the current level
		size_t levelSize = q.size();
		for (size_t i = 0; i < levelSize; i++) {
			Node* node = q.front();
			q.pop();

			if (node->value < 0) {
				// print the level header only before the first negative value
				if (!hasNegatives) {
					std::cout << "Ниво " << level << ":";
					hasNegatives = true;
				}
				std::cout << " " << node->value;
			}

			for (Node* child : node->children) {
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

	// nodes[i] is the node with number i
	std::vector<Node*> nodes(n);
	for (int i = 0; i < n; i++) {
		int value;
		std::cin >> value;
		nodes[i] = new Node(value);
	}

	for (int i = 0; i < e; i++) {
		int parent, child;
		std::cin >> parent >> child;
		nodes[parent]->children.push_back(nodes[child]);
	}

	printNegativesByLevel(nodes[0]);

	for (Node* node : nodes) {
		delete node;
	}
}

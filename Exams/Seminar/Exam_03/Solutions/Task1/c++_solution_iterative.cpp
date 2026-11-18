// Контролно 3 СДА 2026/27, Задача 1 - най-близка стойност в BST

// O(H) time complexity, where H is the height of the tree (O(N) in the worst case, O(logN) for a balanced tree)
// O(1) space complexity

#include <cstdlib>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) : value(value), left(left), right(right) {}
};

int closestValue(TreeNode* root, int target) {
	int closest = root->value;
	TreeNode* node = root;

	// in a BST we go down just like in a binary search - only one path is relevant
	while (node != nullptr) {
		int diff = std::abs(node->value - target);
		int closestDiff = std::abs(closest - target);

		// on a tie we keep the smaller value
		if (diff < closestDiff || (diff == closestDiff && node->value < closest)) {
			closest = node->value;
		}

		if (target < node->value) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return closest;
}

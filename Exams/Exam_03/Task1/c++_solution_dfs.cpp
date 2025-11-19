#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Решение с DFS (Depth-First Search)
// Рекурсивно обхождаме дървото и събираме сумите за всяко ниво
void dfs(TreeNode* node, int level, int& sum) {
    if (!node) return;

    // Ако нивото е четно, добавяме стойността
    if (level % 2 == 0) {
        sum += node->val;
    }

    // Рекурсивно обхождаме лявото и дясното поддърво
    dfs(node->left, level + 1, sum);
    dfs(node->right, level + 1, sum);
}

int sumOfEvenLevels(TreeNode* root) {
    int sum = 0;
    dfs(root, 0, sum);
    return sum;
}

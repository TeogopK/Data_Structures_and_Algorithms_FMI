#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Решение с BFS (Breadth-First Search)
// Обхождаме дървото ниво по ниво и събираме сумите на четните нива
int sumOfEvenLevels(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    int sum = 0;

    while (!q.empty()) {
        int sz = q.size();
        int levelSum = 0;

        // Обхождаме всички възли на текущото ниво
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front();
            q.pop();

            // Ако нивото е четно, добавяме стойността
            if (level % 2 == 0) {
                levelSum += node->val;
            }

            // Добавяме децата в опашката за следващото ниво
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        sum += levelSum;
        ++level;
    }

    return sum;
}
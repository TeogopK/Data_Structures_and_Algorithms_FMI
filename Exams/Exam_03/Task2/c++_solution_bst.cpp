#include <iostream>
#include <climits>
using namespace std;

// Решение 3: Построяване на собствено BST
// Строим BST и търсим най-малкото число строго по-голямо от X

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

// Не трябва да се пише, идва наготово
TreeNode* insert(TreeNode* node, long long val) {
    if (!node) {
        return new TreeNode(val);
    }

    if (val < node->val) {
        node->left = insert(node->left, val);
    }
    else if (val > node->val) {
        node->right = insert(node->right, val);
    }

    return node;
}

// Търсене на най-малкото число строго по-голямо от target
void findSuccessor(TreeNode* node, long long target, long long& result) {
    if (!node) return;

    if (node->val > target) {
        // Възможен кандидат, търсим по-наляво
        result = min(result, node->val);
        findSuccessor(node->left, target, result);
    }
    else {
        // Търсим вдясно
        findSuccessor(node->right, target, result);
    }
}

long long main() {
    long long n;
    cin >> n;

    TreeNode* bst = nullptr;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        bst = insert(bst, x);
    }

    long long target;
    cin >> target;

    long long result = LLONG_MAX;
    findSuccessor(bst, target, result);

    if (result == LLONG_MAX) {
        cout << "NO" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}

// Сложност:
// Време: O(N*H) за вмъкване на N елемента, където H е височината на дървото
//        + O(H) за търсене = O(N*H)
//        В най-лошия случай H = N (дегенерирало дърво), в среден случай H = logN
// Памет: O(N) за дървото

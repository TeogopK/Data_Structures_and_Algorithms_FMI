#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deletePenultimateAndPrint()
    {
        deleteChildrenLeaves(root);
        printTree(root);
    }

    bool hasChildren(Node* root)
    {
        return root->left != nullptr || root->right != nullptr;
    }

    void printTree(Node* root)
    {
        if (!root)
        {
            return;
        }

        printTree(root->left);
        cout << root->value << " ";
        printTree(root->right);
    }

    Node* deleteChildrenLeaves(Node* root)
    {
        if (root == nullptr || (root->right == nullptr && root->left == nullptr))
        {
            return root;
        }

        if (root->left == nullptr)
        {
            if (!hasChildren(root->right))
            {
                Node* temp = root->right;
                delete root;
                root = temp;
                return root;
            }

            root->right = deleteChildrenLeaves(root->right);
        }

        else if (root->right == nullptr)
        {
            if (!hasChildren(root->left))
            {
                Node* temp = root->left;
                delete root;
                root = temp;
                return root;
            }

            root->left = deleteChildrenLeaves(root->left);
        }

        else
        {
            if (!hasChildren(root->left) && !hasChildren(root->right))
            {
                root->right->left = root->left;
                Node* temp = root->right;
                delete root;
                root = temp;
                return root;
            }

            root->right = deleteChildrenLeaves(root->right);
            root->left = deleteChildrenLeaves(root->left);
        }

        return root;
    }

private:
    Node* root;

    // Insert function for BST
    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        return curNode;
    }

};

int main() {
    int n;
    cin >> n; // Number of nodes
    int value;
    BST tree;

    // Read input and build BST
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    // Delete penultimate nodes and print the tree in sorted order
    tree.deletePenultimateAndPrint();

    return 0;
}

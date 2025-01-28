#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
};

vector<Node*> nodes(1e6);

// 0 - I have been painted
// 1 - I have been painted by my child elements (or I am a nullptr for edge cases)
// 2 - I need to be painted by my parent element
size_t fillPaints(Node* root, int& paints)
{
    if(root == nullptr)
    {
        return 1;
    }
    
    if(root->left == nullptr && root->right == nullptr)
    {
        return 2;
    }
    
    int leftPaint = fillPaints(root->left, paints);
    int rightPaint = fillPaints(root->right, paints);

    if(leftPaint == 2 || rightPaint == 2)
    {
        paints++;
        return 0;
    }
    
    if(leftPaint == 0 || rightPaint == 0)
    {
        return 1;
    }
    
    return 2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int verts = 0;
    cin >> verts;
    
    for(int i = 0; i < verts; i++)
    {
        nodes[i] = new Node();
    }
    
    for(int i = 0; i < verts; i++)
    {
        int left, right;
        cin >> left >> right;
        
        if (left != -1)
        {
            nodes[i]->left = nodes[left];
        }
        if(right != -1)
        {
            nodes[i]->right = nodes[right];
        }
    }
    
    int paints = 0;
    int rootState = fillPaints(nodes[0], paints);
    cout << paints + (rootState == 2);
}
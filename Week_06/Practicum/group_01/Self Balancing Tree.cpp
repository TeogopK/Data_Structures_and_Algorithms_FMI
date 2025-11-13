// Note: Implement everything, do not use implemented functions from Hackerrank

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int height(node* n) {
    // Height of a Null node is -1 and the height of the leaf node is 0.
    return  n ? n->ht : -1;
}

void update_height(node* n) {
    n->ht = 1 + max(height(n->left), height(n->right));
}

int balance(node* n) {
    return height(n->left) - height(n->right);
}

node* rotate_right(node* n) {
    node* new_root = n->left;
    node* new_left = new_root->right;
    
    n->left = new_left;
    new_root->right = n;
    
    update_height(n);
    update_height(new_root);
    
    return new_root;
}

node* rotate_left(node* n) {
    node* new_root = n->right;
    node* new_right = new_root->left;
    
    n->right = new_right;
    new_root->left = n;
    
    update_height(n);
    update_height(new_root);
    
    return new_root;
}

node* rotate_left_right(node* n) {
    n->left = rotate_left(n->left);
    return rotate_right(n);
}

node* rotate_right_left(node* n) {
    n->right = rotate_right(n->right);
    return rotate_left(n);
}

node * insert(node * root,int val)
{
	if (!root) {
        auto* n = new node();
        n->val = val;
        n->ht = 0;
        n->left = n->right = nullptr;
        
        return n;
    }
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    else {
        // All the values in the tree will be distinct.
        return root;
    }
    
    update_height(root);
    
    int b = balance(root);
    
    // Left Left Case
    if (b > 1 && val < root->left->val) {
        return  rotate_right(root);
    }
    // Left Right Case
    if (b > 1 && val > root->left->val) {
        return rotate_left_right(root);
    }
    // Right Right Case
    if (b < -1 && val > root->right->val) {
        return  rotate_left(root);
    }
    // Right Left Case
    if (b < -1 && val < root->right->val) {
        return  rotate_right_left(root);
    }
    
    // No balancing needed
    return root;
}


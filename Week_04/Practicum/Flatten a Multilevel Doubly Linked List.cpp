/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// first way
class Solution {
public:
    pair<Node*, Node*> flat(Node* node) {
        Node* head = node;
        Node* next = node->next;

        if (node->child) {
            node->child->prev = node;
            auto p = flat(node->child);
            node->child = nullptr;
            node->next = p.first;
            node = p.second;
        } 


        if (next) {
            auto p = flat(next);
            node->next = p.first;
            node->next->prev = node;
            node = p.second;
        } 

        return {head, node};
    }
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        return flat(head).first;
    }
};

// second way
class Solution2 {
    Node* flattenAndReturnLastNode(Node* node) {
        Node* curr = node;
        while (curr) {
            if (curr->child) {
                Node* last = flattenAndReturnLastNode(curr->child);
                Node* next = curr->next;
                curr->child->prev = curr;
                curr->next = curr->child;
                curr->child = nullptr;

                if (!next) {
                    return last;
                } else {
                    next->prev = last;
                    last->next = next;
                    curr = next;
                }
            } else {
                if (!curr->next) {
                    return curr;
                }
                curr = curr->next;
            }
        }
        
        return curr;
    }

public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        
        flattenAndReturnLastNode(head);
        return head;
    }
};

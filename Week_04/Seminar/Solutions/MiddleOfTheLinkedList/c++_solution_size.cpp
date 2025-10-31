/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* current = head;
        
        while (current) {
            size++;
            current = current->next;
        }
        
        int target = size / 2;
        current = head;
        
        for (int i = 0; i < target; i++) {
            current = current->next;
        }
        
        return current;
    }
};

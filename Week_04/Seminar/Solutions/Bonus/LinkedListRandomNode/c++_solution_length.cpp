// https://leetcode.com/problems/linked-list-random-node/

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
    ListNode* head;
    int size = 0;

public:
    Solution(ListNode* head) : head(head) {
        for(ListNode* current = head; current; current = current->next) {
            size++;
        }
    }

    int getRandom() {
        int steps = rand() % size;

        ListNode* current = head;
        while(steps--) {
            current = current->next;
        }

        return current->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

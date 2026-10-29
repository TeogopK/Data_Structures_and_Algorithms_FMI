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

public:
    Solution(ListNode* head) : head(head) {}

    int getRandom() {
        int count = 0;
        int output = 0;

        for(ListNode* current = head; current; current = current->next) {
            count++;
            // replace the pick with probability 1 / count
            if(rand() % count == 0) {
                output = current->val;
            }
        }

        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

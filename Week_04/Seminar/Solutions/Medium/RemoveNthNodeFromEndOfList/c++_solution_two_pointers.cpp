// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* beforeTarget = head;
        ListNode* lead = head;
        int length = 0;
        // move lead n + 1 nodes ahead, so beforeTarget stops right before the node to remove
        while(length <= n && lead) {
            length++;
            lead = lead->next;
        }
        // move both lead and beforeTarget until lead reaches the end
        while(lead) {
            lead = lead->next;
            beforeTarget = beforeTarget->next;
            length++;
        }
        // the n-th node from the end is the head
        if(length == n) {
            return head->next;
        }
        beforeTarget->next = beforeTarget->next->next;

        return head;
    }
};

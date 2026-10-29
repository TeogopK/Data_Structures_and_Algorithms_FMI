// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode prehead(-1); // on the stack, so it doesn't leak
        ListNode* prev = &prehead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        
        prev->next = l1 ? l1 : l2;

        return prehead.next;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1, dummy2;
        ListNode* l1 = &dummy1, * l2 = &dummy2;

        auto iter = head;
        while (iter) {
            if (iter->val < x) {
                l1->next = iter;
                l1 = l1->next;
            } else {
                l2->next = iter;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        
        l1->next = dummy2.next;
        l2->next = nullptr;
        
        return dummy1.next;
    }
};

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* sorted = new ListNode;
        while(head) {

            ListNode* temp = head->next;
            ListNode* pos = sorted;
            
            while(pos->next && head->val > pos->next->val) {
                pos = pos->next;
            }

            head->next = pos->next;
            pos->next = head;
            head = temp;
        }

        return sorted->next;

    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                // auto toDelete = current->next;
                current->next = current->next->next;
                // delete toDelete;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

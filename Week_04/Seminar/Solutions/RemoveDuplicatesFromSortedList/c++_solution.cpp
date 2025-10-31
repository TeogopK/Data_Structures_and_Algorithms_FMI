class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->val == current->val) {
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

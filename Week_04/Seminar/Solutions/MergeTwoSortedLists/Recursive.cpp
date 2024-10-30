class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }

        if (list1->val > list2->val) {
            swap(list1, list2);
        }

        list1->next = mergeTwoLists(list1->next, list2);
        return list1;        
    }
};

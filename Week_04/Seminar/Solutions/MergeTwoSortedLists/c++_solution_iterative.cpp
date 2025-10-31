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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }
        
        ListNode* result = nullptr;
        if(list1->val < list2->val) {
            result = list1;
            list1 = list1->next;
        }
        else {
            result = list2;
            list2 = list2->next;
        }
        
        ListNode* iter = result;
        
        while(list1 && list2) {
            if(list1->val < list2->val) {
                iter->next = list1;
                list1 = list1->next;
            }
            else {
                iter->next = list2;
                list2 = list2->next;
            }
            iter = iter->next;
        }
        
        while(list1) {
            iter->next = list1;
            list1 = list1->next;
            iter = iter->next;
        }
        
        while(list2) {
            iter->next = list2;
            list2 = list2->next;
            iter = iter->next;
        }
        
        return result;
    }
};

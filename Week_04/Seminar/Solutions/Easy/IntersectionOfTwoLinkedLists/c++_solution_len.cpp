/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int listLength(ListNode* head) {
        int result = 0;
        while(head) {
            head = head->next;
            result++;
        }
        return result;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto lA = listLength(headA);
        auto lB = listLength(headB);
        
        // easier to assume that A has more length
        if(lA < lB) {
            swap(lA, lB);
            swap(headA, headB);
        }
        
        while(lA > lB) {
            headA = headA->next;
            lA--;
        }
        
        while(headA) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
    }
};

// Solution with only one pass!
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
        ListNode* startPrev = head;
        ListNode* iter = head;
        size_t diff = 0;
        while(diff <= n && iter) {
            diff++;
            iter = iter->next;
        }
        
        while(iter) {
            iter = iter->next;
            startPrev = startPrev->next;
            diff++;
        }
        if(diff == n) {
            return head->next;
        }
        startPrev->next = startPrev->next->next;
        
        return head;
    }
};

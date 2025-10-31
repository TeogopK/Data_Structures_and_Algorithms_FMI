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
        if(!head) {
            return nullptr;
        }
        ListNode* l1Head = nullptr;
        ListNode* l1Tail = nullptr;
        ListNode* l2Head = nullptr;
        ListNode* l2Tail = nullptr;

        auto iter = head;
        while(iter) {
            if(iter->val >= x) {
                if(!l2Head) {
                    l2Head = l2Tail = iter; 
                }
                else {
                    l2Tail->next = iter;
                    l2Tail = l2Tail->next;
                }
            }
            else {
                if(!l1Head) {
                    l1Head = l1Tail = iter; 
                }
                else {
                    l1Tail->next = iter;
                    l1Tail = l1Tail->next;
                }
            }
            iter = iter->next;
        }

        if(!l1Head) {
            l2Tail->next = nullptr;
            return l2Head;
        }
        if(!l2Head) {
            l1Tail->next = nullptr;
            return l1Head;
        }

        l1Tail->next = l2Head;
        l2Tail->next = nullptr;
        return l1Head;
    }
};

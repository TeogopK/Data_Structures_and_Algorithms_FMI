// https://leetcode.com/problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while (headA != nullptr) {
            ListNode *iter = headB;
            while (iter != nullptr) {
                if (headA == iter) return headA;
                iter = iter->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

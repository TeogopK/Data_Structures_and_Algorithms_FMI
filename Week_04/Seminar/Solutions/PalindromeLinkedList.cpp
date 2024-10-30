/ Space: O(1) solution
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    int listLength(ListNode* head) {
        int result = 0;
        while(head) {
            head = head->next;
            result++;
        }
        return result;
    }
    bool isPalindrome(ListNode* head) {
        auto headCopy = head;
        auto l = listLength(head);
        
        for(size_t i = 0; i < l / 2; i++, head = head->next) {}
        if(l & 1) {
            head = head->next;
        }
        auto reversed = reverseList(head);
        for(size_t i = 0; i < l / 2; i++, headCopy = headCopy->next, reversed = reversed->next) {
            if(headCopy->val != reversed->val) {
                return false;
            }
        }
        
        return true;
    }
};

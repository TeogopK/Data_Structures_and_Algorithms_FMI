/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        
        int oddEvenIndicator = 1;
        ListNode* lastOddNode = head;
        ListNode* firstEvenNode = head->next;
        ListNode* lastEvenNode = head->next;
        ListNode* currentNode = head->next->next;
        
        while (currentNode != nullptr) {
            if (oddEvenIndicator % 2 == 0) {
                lastEvenNode->next = currentNode;
                lastEvenNode = currentNode;
            } else {
                lastOddNode->next = currentNode;
                lastOddNode = currentNode;
            }
            currentNode = currentNode->next;
            oddEvenIndicator++;
        }
        
        lastOddNode->next = firstEvenNode;
        lastEvenNode->next = nullptr;
        return head;
    }
};

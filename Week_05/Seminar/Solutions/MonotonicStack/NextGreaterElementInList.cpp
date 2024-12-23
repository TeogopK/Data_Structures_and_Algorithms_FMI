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
    size_t l(ListNode* node) {
        size_t length = 0;
        while(node) {
            node = node->next;
            length++;
        }
        return length;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        size_t sizeL = l(head);
        vector<int> result(sizeL, 0);
        // msValue - monotonic stack with values in decreasing order
        // msIndex - stack with indexes of the elements in the order stack
        // msValue->top is the value of the element at position msIndex->top
        stack<int> msIndex, msValue;
        size_t counter = 0;
        while(head) {
            while(!msValue.empty() && msValue.top() < head->val) {
                // write to its position the next greater element
                result[msIndex.top()] = head->val;
                msIndex.pop();
                msValue.pop();
            }
            
            msIndex.push(counter);
            msValue.push(head->val);
            counter++;
            head = head->next;
        }
        
        return result;
    }
};

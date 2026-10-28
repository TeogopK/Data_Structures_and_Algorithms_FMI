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
    vector<ListNode*> pointers; // idx -> ListNode*

public:
    Solution(ListNode* head) {
        while(head) {
            pointers.push_back(head);
            head = head->next;
        }
    }

    int getRandom() {
        int randomIdx = rand() % pointers.size(); // -> O(1)
        return pointers[randomIdx]->val; // -> O(1)
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

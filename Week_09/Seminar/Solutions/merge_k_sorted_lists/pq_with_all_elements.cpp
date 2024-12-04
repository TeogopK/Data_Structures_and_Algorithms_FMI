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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(size_t i = 0; i < lists.size(); i++) {
            auto iter = lists[i];
            while(iter) {
                pq.push(iter->val);
                iter = iter->next;
            }
        }
        
        if(pq.empty()) {
            return nullptr;
        }
        ListNode* resultHead = new ListNode(pq.top());
        ListNode* iter = resultHead;
        pq.pop();
        while(!pq.empty()) {
            iter->next = new ListNode(pq.top());
            iter = iter->next;
            pq.pop();
        }
    
        return resultHead;
    }
};

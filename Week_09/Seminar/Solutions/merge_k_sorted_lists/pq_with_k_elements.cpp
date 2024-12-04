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

struct Comparator {
    bool operator()(const ListNode* lhs, const ListNode* rhs) {
        return lhs->val > rhs->val;
    }  
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;
        for(size_t i = 0; i < lists.size(); i++) {
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(pq.empty()) {
            return nullptr;
        }
        ListNode* resultHead = pq.top();
        ListNode* iter = resultHead;
        if(resultHead->next) {
            pq.push(resultHead->next);
        }
        
        pq.pop();
        while(!pq.empty()) {
            iter->next = pq.top();
            iter = iter->next;
            pq.pop();
            if(iter->next) {
                pq.push(iter->next);
            }
        }
        
        return resultHead;
    }
};

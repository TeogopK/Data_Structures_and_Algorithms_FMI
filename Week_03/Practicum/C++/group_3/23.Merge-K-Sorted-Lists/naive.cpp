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
        ListNode* res = new ListNode(INT_MAX);
        int idx = -1;
        bool ready = true;
        for(int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr && lists[i]->val < res->val) {
                res->val = lists[i]->val;
                idx = i;
                ready = false;
            }
        }
        if (ready) {
            delete res;
            return nullptr;
        }
        lists[idx] = lists[idx]->next;
        rec(lists, res);
        return res;
    }

    ListNode* rec(vector<ListNode*>& lists, ListNode* cur) {
        ListNode* res = new ListNode(INT_MAX);
        int idx = -1;
        bool ready = true;
        for(int i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr && lists[i]->val < res->val) {
                res->val = lists[i]->val;
                idx = i;
                ready = false;
            }
        }
        if (ready) {
            delete res;
            return cur;
        }
        lists[idx] = lists[idx]->next;
        cur->next = rec(lists, res);
        return cur;
    }
};

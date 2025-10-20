//N is the sum of all elements count
//K is the count of sorted linked lists

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
        if (lists.empty()) {
            return nullptr;
        }
        return devideConquer(lists);
    }

    ListNode* devideConquer(vector<ListNode*>& lists) {
        if (lists.size() == 1) {
            return lists[0];
        }

        int mid = lists.size() / 2;
        vector<ListNode*> lhs(lists.begin(), lists.begin() + mid);
        vector<ListNode*> rhs(lists.begin() + mid, lists.end());
        return merge(devideConquer(lhs), devideConquer(rhs));
    }

    ListNode* merge(ListNode* lhs, ListNode* rhs) {
        if (!lhs) {
            return rhs;
        }
        if (!rhs) {
            return lhs;
        }

        if (lhs->val > rhs->val) {
            swap(lhs, rhs);
        }

        ListNode* res = lhs;

        while(lhs->next && rhs) {
            if (lhs->next->val > rhs->val) {
                ListNode* tmp = lhs->next;
                lhs->next = rhs;
                rhs = tmp;
            }
            lhs = lhs->next;
        }
        if (!lhs->next) {
            lhs->next = rhs;
        }

        return res;
    }
};

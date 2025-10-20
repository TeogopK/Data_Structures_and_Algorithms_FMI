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
        return devideConquer(lists, 0, lists.size() - 1);
    }

    ListNode* devideConquer(vector<ListNode*>& lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        int mid = (r - l) / 2 + l;
        return merge(devideConquer(lists, l, mid), devideConquer(lists, mid + 1, r));
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

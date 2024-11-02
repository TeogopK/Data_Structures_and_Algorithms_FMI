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
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int active = lists.size();
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(active > 0) {
            int index = -1;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && (index == -1 || lists[index]->val > lists[i]->val)) {
                    index = i;
                }
            }
            if (index == -1)
                break;

            curr->next = lists[index];
            curr = curr->next;
            lists[index] = lists[index]->next;

            if (!lists[index])  
                active--;
        }

        return dummy->next;

    }
};

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
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* mid = getMid(head);

        ListNode* right = sortList(mid->next);
        mid->next = nullptr;
        ListNode* left = sortList(head);

        return merge(left, right);
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        }
        if (list2) {
            tail->next = list2;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (ListNode* list : lists) {
             while (list) {
                tail->next = list;
                list = list->next;
                tail = tail->next;
            }
        }
        return sortList(dummy->next);
    }
};
class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        // edge cases when the while loop stops
        // 1 2 3 4 5 - odd elements count
        //     s   f
        // 1 2 3 4 5 6 - even elements count
        //     s   f
        // 0  3 - two elements
        // sf
        auto slow = list;
        auto fast = list;
        while(fast->next != list && fast->next->next != list) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto secondList = slow->next;
        if(fast->next == list) {
            fast->next = secondList;
        }
        else {
            fast->next->next = secondList;
        }
        
        slow->next = list;
        return { list, secondList };
    }
};
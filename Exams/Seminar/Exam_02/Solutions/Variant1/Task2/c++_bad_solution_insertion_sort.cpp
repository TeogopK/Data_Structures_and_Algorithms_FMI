// Контролно 2 СДА 2026/27, Вариант 1, Задача 2 - noiseFilterMerge

// O((N + M)^2) time complexity, where N and M are the lengths of the two lists
// O(1) additional space complexity - we reuse the nodes of the input lists
// The solution doesn't use the fact that the input lists are sorted

struct ListNode {
	int value;
	ListNode* next;

	ListNode(int v, ListNode* n = nullptr) : value(v), next(n) {}
};

// Inserts node into the sorted list head and returns the (possibly new) head - O(length of head)
ListNode* insertSorted(ListNode* head, ListNode* node) {
	if (head == nullptr || node->value < head->value) {
		node->next = head;
		return node;
	}

	// Find the last node with value <= node->value
	ListNode* iter = head;
	while (iter->next != nullptr && iter->next->value <= node->value) {
		iter = iter->next;
	}

	node->next = iter->next;
	iter->next = node;
	return head;
}

// Deletes the noise nodes of list and inserts the others one by one into result
ListNode* insertAll(ListNode* result, ListNode* list) {
	while (list != nullptr) {
		ListNode* next = list->next;

		if (list->value < 0) {
			delete list;
		}
		else {
			result = insertSorted(result, list);
		}

		list = next;
	}
	return result;
}

ListNode* noiseFilterMerge(ListNode* first, ListNode* second) {
	ListNode* result = nullptr;
	result = insertAll(result, first);
	result = insertAll(result, second);
	return result;
}

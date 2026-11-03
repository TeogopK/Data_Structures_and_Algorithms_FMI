// Контролно 2 СДА 2026/27, Вариант 2, Задача 2 - filterRocksSortDesc

// O(N + M) time complexity, where N and M are the lengths of the two lists
// O(N + M) space complexity - for the recursion stack (we still reuse the nodes of the input lists)

struct ListNode {
	int value;
	ListNode* next;

	ListNode(int v, ListNode* n = nullptr) : value(v), next(n) {}
};

// Deletes the rock (zero) nodes at the front of the list
// and returns the first normal node (or nullptr)
ListNode* skipRocks(ListNode* node) {
	while (node != nullptr && node->value == 0) {
		ListNode* next = node->next;
		delete node;
		node = next;
	}
	return node;
}

ListNode* filterRocksSortDesc(ListNode* first, ListNode* second) {
	first = skipRocks(first);
	second = skipRocks(second);

	if (first == nullptr && second == nullptr) {
		return nullptr;
	}

	// Take the bigger head (or the only one left) and merge the rest after it.
	// When one list is over we keep recursing on the other, so its rocks are removed too
	if (second == nullptr || (first != nullptr && first->value >= second->value)) {
		first->next = filterRocksSortDesc(first->next, second);
		return first;
	}

	second->next = filterRocksSortDesc(first, second->next);
	return second;
}

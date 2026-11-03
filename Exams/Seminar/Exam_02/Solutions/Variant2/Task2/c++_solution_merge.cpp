// Контролно 2 СДА 2026/27, Вариант 2, Задача 2 - filterRocksSortDesc

// O(N + M) time complexity, where N and M are the lengths of the two lists
// O(1) additional space complexity - we reuse the nodes of the input lists

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
	// Dummy node on the stack, so we don't need a special case for the head of the result
	ListNode dummy(0);
	ListNode* tail = &dummy;

	first = skipRocks(first);
	second = skipRocks(second);

	// Classic merge of two sorted lists, but in descending order (we take the bigger value) -
	// after taking a node we skip (and delete) the rocks right after it
	while (first != nullptr && second != nullptr) {
		if (first->value >= second->value) {
			tail->next = first;
			first = skipRocks(first->next);
		}
		else {
			tail->next = second;
			second = skipRocks(second->next);
		}
		tail = tail->next;
	}

	// The rest of the remaining list can still contain rocks, so we can't just attach it
	ListNode* rest = (first != nullptr) ? first : second;
	while (rest != nullptr) {
		tail->next = rest;
		tail = rest;
		rest = skipRocks(rest->next);
	}

	// The last taken node may still point to an already deleted rock node
	tail->next = nullptr;

	return dummy.next;
}

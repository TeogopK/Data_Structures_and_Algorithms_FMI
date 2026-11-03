// Контролно 2 СДА 2026/27, Вариант 1, Задача 2 - noiseFilterMerge

// O(N + M) time complexity, where N and M are the lengths of the two lists
// O(N + M) space complexity - for the recursion stack (we still reuse the nodes of the input lists)

struct ListNode {
	int value;
	ListNode* next;

	ListNode(int v, ListNode* n = nullptr) : value(v), next(n) {}
};

// Deletes the noise (negative) nodes at the front of the list
// and returns the first normal node (or nullptr)
ListNode* skipNoise(ListNode* node) {
	while (node != nullptr && node->value < 0) {
		ListNode* next = node->next;
		delete node;
		node = next;
	}
	return node;
}

ListNode* noiseFilterMerge(ListNode* first, ListNode* second) {
	first = skipNoise(first);
	second = skipNoise(second);

	if (first == nullptr && second == nullptr) {
		return nullptr;
	}

	// Take the smaller head (or the only one left) and merge the rest after it.
	// When one list is over we keep recursing on the other, so its noise is removed too
	if (second == nullptr || (first != nullptr && first->value <= second->value)) {
		first->next = noiseFilterMerge(first->next, second);
		return first;
	}

	second->next = noiseFilterMerge(first, second->next);
	return second;
}

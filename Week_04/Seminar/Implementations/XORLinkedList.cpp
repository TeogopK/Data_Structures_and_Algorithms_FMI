#include <iostream>
#include <utility>

// Not fully implemented but has the fundamental stuff
template<typename T>
class XORLinkedList {
private:
	struct Node {
		T value;
		Node* nextXORPrev;

		Node(const T& value, Node* nextXORPrev = nullptr)
			: value(value), nextXORPrev(nextXORPrev) { }
	};

	Node* head = nullptr, * tail = nullptr;

	static Node* XOR(Node* a, Node* b) {
		return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
	}
public:
	XORLinkedList() = default;
	// Deleting copy and move to simplify the implementation
	XORLinkedList(const XORLinkedList&) = delete;
	XORLinkedList& operator=(const XORLinkedList&) = delete;
	~XORLinkedList();

	void push_front(const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();
	bool contains(const T&) const;

	const T& front() const;
	const T& back() const;

	void print() const;

private:
	void free();
};

template<typename T>
XORLinkedList<T>::~XORLinkedList() {
	free();
}

template<typename T>
void XORLinkedList<T>::push_front(const T& value) {
	Node* newNode = new Node(value);
	if (head == nullptr) {
		head = tail = newNode;
		return;
	}

	Node* previousHead = head;
	newNode->nextXORPrev = previousHead; // XOR of nullptr and head is head
	head = newNode;

	// Update the nextXORPrev of the previous head
	// should be XOR of new head and next of previous head
	previousHead->nextXORPrev = XOR(head, previousHead->nextXORPrev);
}

template<typename T>
void XORLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);
	if (tail == nullptr) {
		head = tail = newNode;
		return;
	}

	Node* previousTail = tail;
	newNode->nextXORPrev = previousTail; // XOR of nullptr and tail is tail
	tail = newNode;
	// PreviousTail->nextXORPrev is XOR of prev and nullptr => should be updated to XOR of prev and new tail
	previousTail->nextXORPrev = XOR(tail, previousTail->nextXORPrev);
}

template<typename T>
void XORLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* previousHead = head;
	Node* newHead = head->nextXORPrev;
	delete head;
	head = newHead;
	if (head) {
		head->nextXORPrev = XOR(previousHead, head->nextXORPrev);
	}
	else {
		tail = nullptr;
	}
}

template<typename T>
void XORLinkedList<T>::pop_back() {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	Node* previousTail = tail;
	Node* newTail = tail->nextXORPrev;
	delete tail;
	tail = newTail;
	if (tail) {
		tail->nextXORPrev = XOR(previousTail, tail->nextXORPrev);
	}
	else {
		head = nullptr;
	}
}

template<typename T>
bool XORLinkedList<T>::contains(const T& value) const {
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		if(current->value == value) {
			return true;
		}
		// current->nextXORPrev is XOR of prev and next
		// if xor it with prev we get next
		Node* next = XOR(prev, current->nextXORPrev);
		prev = current;
		current = next;
	}

	return false;
}

template<typename T>
const T& XORLinkedList<T>::front() const {
	if (!head) {
		throw std::length_error("List is empty");
	}

	return head->value;
}

template<typename T>
const T& XORLinkedList<T>::back() const {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	return tail->value;
}

template<typename T>
void XORLinkedList<T>::print() const {
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		std::cout << current->value << ' ';
		// current->nextXORPrev is XOR of prev and next
		// if xor it with prev we get next
		Node* next = XOR(prev, current->nextXORPrev);
		prev = current;
		current = next;
	}
}

template<typename T>
void XORLinkedList<T>::free() {
	Node* current = head;
	Node* prev = nullptr;
	while (current) {
		Node* next = XOR(prev, current->nextXORPrev);
		prev = current;
		delete current;
		current = next;
	}
	head = tail = nullptr;
}

//int main() {
//	XORLinkedList<int> list;
//	list.push_front(1);
//	list.push_front(2);
//	list.push_front(3);
//	list.push_front(4);
//	list.push_front(5);
//	list.pop_front();
//	list.pop_front();
//	list.push_back(6);
//	list.pop_back();
//	list.pop_back();
//	list.print();
//}

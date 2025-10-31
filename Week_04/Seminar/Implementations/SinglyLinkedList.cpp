#pragma once
#include <exception>

// reviewed
template<typename T>
class SinglyLinkedList {
private:
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node* next = nullptr)
			: value(value), next(next) {
		}
	};

	Node* head, * tail;
	size_t size = 0;

public:
	// I think you don't need move for the state exam
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<T>&);
	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&);
	~SinglyLinkedList();

	void push_front(const T&); // oh no move semantics are missing for push_fron, push_back and insert
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void remove(const T&);
	bool contains(const T&) const;
	size_t getSize() const;

	const T& front() const;
	const T& back() const;

private:
	void copyFrom(const SinglyLinkedList<T>&);
	void free();
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	head = tail = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
	copyFrom(other);
}

template<typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	free();
}

// can be optimized with recursion
template<typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other) {
	Node* iter = other.head;
	size = other.size;

	while (iter) {
		push_back(iter->value);
		iter = iter->next;
	}
}

template<typename T>
void SinglyLinkedList<T>::free() {
	Node* iter = head;

	while (iter) {
		Node* next = iter->next;
		delete iter;
		iter = next;
	}

	head = tail = nullptr;
	size = 0;
}

template <typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
	size++;
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T& value) {
	Node* newNode = new Node(value);

	if (!head) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	size++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::exception("List is empty");
	}

	Node* temp = head;
	head = head->next;
	delete temp;

	// in case we had only one element
	if (!head) {
		tail = nullptr;
	}
	size--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
	if (!head) {
		throw std::length_error("List is empty");
	}
	// watch out da ne se vikat vzaimno po tozi nachin pop_front i pop_back!!!
	if (head == tail) {
		pop_front();
		return;
	}

	Node* prev = nullptr;
	Node* iter = head; // iter will be poiting to the last element after the loop
	while (iter != tail) {
		prev = iter;
		iter = iter->next;
	}

	prev->next = nullptr;
	tail = prev;

	delete iter;
	size--;
}

template<typename T>
void SinglyLinkedList<T>::remove(const T& element) {
	if (!head) {
		throw std::exception("List is empty");
	}

	if (head->value == element) {
		pop_front();
		return;
	}

	Node* prev = nullptr;
	Node* iter = head;

	for (iter != nullptr) {
		if (iter->value == element) {
			break;
		}

		prev = iter;
		iter = iter->next;
	}

	prev->next = iter->next;
	if (iter == tail) {
		tail = prev;
	}

	delete iter;
	size--;
}

template<typename T>
bool SinglyLinkedList<T>::contains(const T& value) const {
	Node* iter = head;

	while (iter) {
		if (iter->value == value) {
			return true;
		}

		iter = iter->next;
	}

	return false;
}

template<typename T>
size_t SinglyLinkedList<T>::getSize() const {
	return size;
}

template<typename T>
const T& SinglyLinkedList<T>::front() const {
	if (!head) {
		throw std::length_error("List is empty");
	}

	return head->value;
}

template<typename T>
const T& SinglyLinkedList<T>::back() const {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	return tail->value;
}

//int main() {
//	SinglyLinkedList<int> list;
//	list.push_back(1);
//	list.push_back(2);
//	list.push_back(3);
//	list.push_back(4);
//	list.push_back(5);
//
//	list.print();
//
//	list.pop_front();
//	list.print();
//
//	list.pop_back();
//	list.print();
//
//	list.insert(10, 2);
//	list.print();
//
//	list.remove(1);
//	list.print();
//
//	std::cout << list.contains(10) << "\n";
//	std::cout << list.contains(100) << "\n";
//
//	std::cout << list.front() << "\n";
//	std::cout << list.back() << "\n";
//
//	return 0;
//}

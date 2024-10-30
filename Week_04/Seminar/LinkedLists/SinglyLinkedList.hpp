#include <iostream>
#include <utility>

template<typename T>
class SinglyLinkedList {
private:
	struct Node {
		T value;
		Node* next;

		Node(const T& value, Node* next = nullptr)
			: value(value), next(next) { }
	};

	Node* head, * tail;

public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<T>&);
	SinglyLinkedList(SinglyLinkedList<T>&&) noexcept;
	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&);
	SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&&) noexcept;
	~SinglyLinkedList();

	void push_front(const T&); // oh no move semantics are missing for push_fron, push_back and insert
	void push_back(const T&);
	void pop_front();
	void pop_back();
	void insert(const T&, size_t);
	void remove(size_t);
	bool contains(const T&) const;

	const T& front() const;
	const T& back() const;

	void print() const;

private:
	void moveFrom(SinglyLinkedList<T>&&) noexcept;
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
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& other) noexcept {
	moveFrom(std::move(other));
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
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	free();
}

template<typename T>
void SinglyLinkedList<T>::moveFrom(SinglyLinkedList<T>&& other) noexcept {
	head = other.head;
	tail = other.tail;

	other.head = other.tail = nullptr;
}

template<typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other) {
	Node* iter = other.head;

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
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* temp = head;
	head = head->next;
	delete temp;

	// in case we had only one element
	if (!head) {
		tail = nullptr;
	}
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* prev = nullptr;
	Node* iter = head; // iter will be poiting to the last element after the loop
	while (iter != tail) {
		prev = iter;
		iter = iter->next;
	}

	if (iter == head) { // in case we had only one element
		head = tail = nullptr;
	}
	else {
		prev->next = nullptr;
		tail = prev;
	}

	delete iter;
}

template<typename T>
void SinglyLinkedList<T>::insert(const T& value, size_t index) {
	if (index == 0) {
		push_front(value);
		return;
	}

	Node* prev = nullptr;
	Node* iter = head;
	for (size_t i = 0; i < index; i++) {
		if (!iter) {
			throw std::out_of_range("Index out of range");
		}

		prev = iter;
		iter = iter->next;
	}

	Node* newNode = new Node(value, iter);
	prev->next = newNode;
	if (tail == prev) {
		tail = newNode;
	}
}

template<typename T>
void SinglyLinkedList<T>::remove(size_t index) {
	if (index == 0) {
		pop_front();
		return;
	}

	Node* prev = nullptr;
	Node* iter = head;

	for (size_t i = 0; i < index; i++) {
		if (!iter->next) {
			throw std::out_of_range("Index out of range");
		}

		prev = iter;
		iter = iter->next;
	}

	prev->next = iter->next;
	if (iter == tail) {
		tail = prev;
	}

	delete iter;
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

template<typename T>
void SinglyLinkedList<T>::print() const {
	Node* iter = head;

	while (iter) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}

	std::cout << "\n";
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

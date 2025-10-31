#pragma once
#include <exception>
#include <iostream>

// reviewed
template<typename T>
class DoublyLinkedList {
private:
	struct Node {
		T value;
		Node* prev, * next;

		Node(const T& value, Node* prev = nullptr, Node* next = nullptr)
			: value(value), prev(prev), next(next) { }
	};

	Node* head, * tail;
	size_t length = 0;
public:
	// missing move semantics
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>&);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>&);
	~DoublyLinkedList();

	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	bool contains(const T& value) const;

	const T& front() const;
	const T& back() const;
	size_t getLength() const;

	void print() const;

private:
	void copyFrom(const DoublyLinkedList<T>&);
	void free();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	head = tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) {
	copyFrom(other);
}

template<typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	free();
}

template<typename T>
void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other) {
	Node* iter = other.head;
	while (iter) {
		push_back(iter->value);
		iter = iter->next;
	}
}

template<typename T>
void DoublyLinkedList<T>::free() {
	Node* iter = head;

	while (iter) {
		Node* next = iter->next;
		delete iter;
		iter = next;
	}

	length = 0;
	head = tail = nullptr;
}


template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
	if (!head) {
		head = tail = new Node(value);
		length = 1;
		return;
	}

	Node* newNode = new Node(value, nullptr, head);
	head->prev = newNode;
	head = newNode;
	length++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	if (!tail) {
		head = tail = new Node(value);
		length = 1;
		return;
	}

	Node* newNode = new Node(value, tail);
	tail->next = newNode;
	tail = newNode;
	length++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
	if (!head) {
		throw std::length_error("List is empty");
	}

	Node* toDelete = head;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}

	delete toDelete;
	length--;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	Node* toDelete = tail;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}

	delete toDelete;
	length--;
}

template<typename T>
bool DoublyLinkedList<T>::contains(const T& value) const {
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
const T& DoublyLinkedList<T>::front() const {
	if (!head) {
		throw std::length_error("List is empty");
	}

	return head->value;
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
	if (!tail) {
		throw std::length_error("List is empty");
	}

	return tail->value;
}

template<typename T>
size_t DoublyLinkedList<T>::getLength() const {
	return length;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
	Node* iter = head;

	while (iter) {
		std::cout << iter->value << " ";
		iter = iter->next;
	}

	std::cout << '\n';
}

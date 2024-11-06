#pragma once
#include <exception>

template<typename T>
class Stack {
private:

	struct Node {
		T data;
		Node* next;

		Node(const T& data, Node* next = nullptr);
		Node(T&& data, Node* next = nullptr);
	};

	Node* top = nullptr;
	size_t size = 0;

public:
	Stack() = default;
	Stack(const Stack<T>& other);
	Stack(Stack<T>&& other) noexcept;
	Stack<T>& operator=(const Stack<T>& other);
	Stack<T>& operator=(Stack<T>&& other) noexcept;
	~Stack();

	void push(const T& data);
	void push(T&& data);
	void pop();

	const T& peek() const;
	size_t getSize() const;
	bool isEmpty() const;

private:
	void move(Stack<T>&& other) noexcept;
	void copyFrom(const Stack<T>& other);
	void free();
};

template<typename T>
Stack<T>::Node::Node(const T& data, Stack<T>::Node* next)
	: data(data), next(next) { }

template<typename T>
Stack<T>::Node::Node(T&& data, Stack<T>::Node* next)
	: data(std::move(data)), next(next) { }


template<typename T>
Stack<T>::Stack(const Stack<T>& other) {
	copyFrom(other);
}

template<typename T>
Stack<T>::Stack(Stack<T>&& other) noexcept {
	move(std::move(other));
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
Stack<T>::~Stack() {
	free();
}

template<typename T>
void Stack<T>::push(const T& data) {
	top = new Node(data, top);
	size++;
}

template<typename T>
void Stack<T>::push(T&& data) {
	top = new Node(std::move(data), top);
	size++;
}

template<typename T>
void Stack<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Empty collection");
	}

	Node* toDelete = top;
	top = top->next;
	delete toDelete;
	--size;
}

template<typename T>
const T& Stack<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("Empty collection");
	}

	return top->data;
}

template<typename T>
size_t Stack<T>::getSize() const {
	return size;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
void Stack<T>::move(Stack<T>&& other) noexcept {
	size = other.size;
	top = other.top;
	other.top = nullptr;
}

template<typename T>
void Stack<T>::copyFrom(const Stack<T>& other) {
	if (other.size == 0) {
		top = nullptr;
		size = 0;
		return;
	}

	size = other.size;
	Node* toCopyIter = other.top;
	Node* currentIter = new Node(toCopyIter->data);

	top = currentIter;
	toCopyIter = toCopyIter->next;

	while (toCopyIter) {
		currentIter->next = new Node(toCopyIter->data);
		currentIter = currentIter->next;
		toCopyIter = toCopyIter->next;
	}
}

template<typename T>
void Stack<T>::free() {
	Node* toDelete = top;

	while (top) {
		toDelete = top;
		top = top->next;
		delete toDelete;
	}

	size = 0;
}

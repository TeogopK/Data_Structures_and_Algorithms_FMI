#pragma once
#include <exception>

template<typename T, const size_t capacity>
class FixedLengthStack {
private:
	T data[capacity];
	size_t size = 0;

public:
	void push(const T& obj);
	void push(T&& obj);

	void pop();
	const T& peek() const;
	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T, const size_t capacity>
void FixedLengthStack<T, capacity>::push(const T& obj) {
	if (size == capacity) {
		throw std::exception("Stack is full");
	}

	data[size++] = obj;
}

template<typename T, const size_t capacity>
void FixedLengthStack<T, capacity>::push(T&& obj) {
	if (size == capacity) {
		throw std::exception("Stack is full");
	}

	data[size++] = std::move(obj);
}

template<typename T, const size_t capacity>
void FixedLengthStack<T, capacity>::pop() {
	if (isEmpty()) {
		throw std::exception("Already empty");
	}

	--size;
}

template<typename T, const size_t capacity>
const T& FixedLengthStack<T, capacity>::peek() const {
	if (isEmpty()) {
		throw std::exception("Stack is empty");
	}

	return data[size - 1];
}

template<typename T, const size_t capacity>
bool FixedLengthStack<T, capacity>::isEmpty() const {
	return size == 0;
}

template<typename T, const size_t capacity>
size_t FixedLengthStack<T, capacity>::getSize() const {
	return size;
}

template<typename T, const size_t capacity>
void FixedLengthStack<T, capacity>::clear() {
	size = 0;
}

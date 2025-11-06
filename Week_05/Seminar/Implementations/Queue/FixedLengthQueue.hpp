#pragma once
#include <exception>

template<typename T, const size_t capacity>
class FixedLengthQueue {
private:
	T data[capacity];
	size_t size = 0;

	size_t get = 0, put = 0;
public:
	void push(const T& obj);
	void pop();
	const T& peek() const; // front

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T, size_t capacity>
void FixedLengthQueue<T, capacity>::push(const T& obj) {
	if (size == capacity) {
		throw std::exception("Queue is full");
	}
	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template<typename T, size_t capacity>
void FixedLengthQueue<T, capacity>::pop() {
	if (size == 0) {
		throw std::exception("Queue is empty");
	}
	(++get) %= capacity;
	size--;
}

template<typename T, size_t capacity>
const T& FixedLengthQueue<T, capacity>::peek() const {
	if (size == 0) {
		throw std::exception("Queue is empty");
	}
	return data[get];
}

template<typename T, size_t capacity>
bool FixedLengthQueue<T, capacity>::isEmpty() const {
	return size == 0;
}

template<typename T, size_t capacity>
size_t FixedLengthQueue<T, capacity>::getSize() const {
	return size;
}

template<typename T, size_t capacity>
void FixedLengthQueue<T, capacity>::clear() {
	size = 0;
}

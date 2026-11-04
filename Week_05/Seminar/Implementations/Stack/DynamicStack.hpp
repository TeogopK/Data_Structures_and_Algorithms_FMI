#pragma once
#include <exception>

template<typename T>
class DynamicStack {
private:
	T* data;
	size_t size = 0;
	size_t capacity = 4; // constant

	// memory management
	void freeDynamic();
	void copyDynamic(const DynamicStack<T>& other);
	// there are several diff implementations of resize => your choice
	void resize();
public:
	// memory management
	DynamicStack();
	DynamicStack(const DynamicStack<T>& other);
	DynamicStack<T>& operator=(const DynamicStack<T>& other);
	~DynamicStack();

	void push(const T& obj);
	void pop();
	const T& peek() const; // top

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T>
void DynamicStack<T>::freeDynamic() {
	delete[] data;
}

template<typename T>
void DynamicStack<T>::copyDynamic(const DynamicStack<T>& other) {
	data = new T[other.capacity];
	for (size_t i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
void DynamicStack<T>::resize() {
	size_t newCapacity = capacity * 2;
	T* newData = new T[newCapacity];
	for (size_t i = 0; i < size; i++) {
		newData[i] = std::move(data[i]);
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
}

template<typename T>
DynamicStack<T>::DynamicStack() : data(new T[capacity])
{ }

template<typename T>
DynamicStack<T>::DynamicStack(const DynamicStack<T>& other)
	: capacity(other.capacity), size(other.size) {
	copyDynamic(other);
}

template<typename T>
DynamicStack<T>& DynamicStack<T>::operator=(const DynamicStack<T>& other) {
	if (this != &other) {
		freeDynamic();
		size = other.size;
		capacity = other.capacity;
		copyDynamic(other);
	}
	return *this;
}

template<typename T>
DynamicStack<T>::~DynamicStack() {
	freeDynamic();
}

template<typename T>
void DynamicStack<T>::push(const T& obj) {
	if (size == capacity) {
		resize();
	}
	data[size++] = obj;
}

template<typename T>
void DynamicStack<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Stack is empty");
	}
	--size;
}

template<typename T>
const T& DynamicStack<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("Stack is empty");
	}
	return data[size - 1];
}

template<typename T>
bool DynamicStack<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
size_t DynamicStack<T>::getSize() const {
	return size;
}

template<typename T>
void DynamicStack<T>::clear() {
	size = 0;
}

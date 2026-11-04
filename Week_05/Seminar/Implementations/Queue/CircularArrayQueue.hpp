#pragma once
#include <exception>

template<typename T>
class DynamicLengthQueue {
private:
	T* data;
	size_t size = 0;
	size_t capacity = 4; // constant

	size_t get = 0, put = 0;

	void resize();
	void copyDynamic(const DynamicLengthQueue<T>& other);
	void freeDynamic();
public:
	DynamicLengthQueue();
	DynamicLengthQueue(const DynamicLengthQueue<T>& other);
	DynamicLengthQueue<T>& operator=(const DynamicLengthQueue<T>& other);
	~DynamicLengthQueue();

	void push(const T& obj);
	void pop();
	const T& peek() const; // front

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T>
DynamicLengthQueue<T>::DynamicLengthQueue() : data(new T[capacity]) {}

template<typename T>
DynamicLengthQueue<T>::DynamicLengthQueue(const DynamicLengthQueue<T>& other)
	: capacity(other.capacity), size(other.size), get(other.get), put(other.put) 
{
	copyDynamic(other);
}

template<typename T>
DynamicLengthQueue<T>& DynamicLengthQueue<T>::operator=(const DynamicLengthQueue<T>& other) {
	if (this != &other) {
		freeDynamic();
		size = other.size;
		capacity = other.capacity;
		get = other.get;
		put = other.put;
		copyDynamic(other);
	}
	return *this;
}

template<typename T>
DynamicLengthQueue<T>::~DynamicLengthQueue() {
	freeDynamic();
}

template<typename T>
void DynamicLengthQueue<T>::copyDynamic(const DynamicLengthQueue<T>& other) {
	data = new T[other.capacity];

	for (int i = 0; i < other.capacity; i++) {
		data[i] = other.data[i];
	}
}

template<typename T>
void DynamicLengthQueue<T>::freeDynamic() {
	delete[] data;
}

template<typename T>
void DynamicLengthQueue<T>::resize() {
	T* resizedData = new T[capacity * 2];
	for (size_t i = 0; i < size; i++) {
		resizedData[i] = data[get];
		(++get) %= capacity;
	}
	capacity *= 2;
	delete[] data;
	data = resizedData;
	get = 0;
	put = size;
}

template<typename T>
void DynamicLengthQueue<T>::push(const T& obj) {
	if (size == capacity) {
		resize();
	}
	data[put] = obj;
	(++put) %= capacity;
	size++;
}

template<typename T>
void DynamicLengthQueue<T>::pop() {
	if (size == 0) {
		throw std::exception("Queue is empty");
	}
	(++get) %= capacity;
	size--;
}

template<typename T>
const T& DynamicLengthQueue<T>::peek() const {
	if (size == 0) {
		throw std::exception("Queue is empty");
	}
	return data[get];
}

template<typename T>
bool DynamicLengthQueue<T>::isEmpty() const {
	return size == 0;
}

template<typename T>
size_t DynamicLengthQueue<T>::getSize() const {
	return size;
}

template<typename T>
void DynamicLengthQueue<T>::clear() {
	size = 0;
	get = put = 0;
}

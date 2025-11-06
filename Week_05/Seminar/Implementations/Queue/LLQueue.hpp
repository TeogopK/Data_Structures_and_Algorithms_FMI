#pragma once
#include <list>
#include <exception>

template<typename T>
class LLQueue {
	// You should not use std::list here
	// imagine that there is a custom implementation of the list here (Singly or doubly)
	// depending on it you
	// might have to add size property
	// might have to change the implementation of some props
	std::list<T> data;
public:
	void push(const T& obj);
	void pop();
	const T& peek() const; // front

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

template<typename T>
void LLQueue<T>::push(const T& obj) {
	data.push_back(obj); // Add to the end of the queue
}

template<typename T>
void LLQueue<T>::pop() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	data.pop_front();
}

template<typename T>
const T& LLQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	return data.front();
}

template<typename T>
bool LLQueue<T>::isEmpty() const {
	return data.size() == 0;
}

template<typename T>
size_t LLQueue<T>::getSize() const {
	return data.size();
}

template<typename T>
void LLQueue<T>::clear() {
	data.clear();
}

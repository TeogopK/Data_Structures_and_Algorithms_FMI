# Queue interface

Стандартен интерфейс

```c++
class Queue {
public:
	void push(const T& obj);
	void pop();
	const T& peek() const; // front

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};

```

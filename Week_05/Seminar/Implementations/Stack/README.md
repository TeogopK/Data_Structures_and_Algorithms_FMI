# Stack

Стандартен интерфейс:

```c++
class StackInterface {
public:
	void push(const T& obj);
	void pop();
	const T& peek() const; // top

	bool isEmpty() const;
	size_t getSize() const;
	void clear();
};
```

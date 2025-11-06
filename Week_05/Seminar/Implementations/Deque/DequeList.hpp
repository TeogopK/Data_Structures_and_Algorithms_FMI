template<typename T>
class Deque {
private:
	std::list<T> list;
public:
	void push_back(const T& value) {
		list.push_back(value);
	}
	void push_front(const T& value) {
		list.push_front(value);
	}
	T& front() {
		return list.front();
	}
	T& back() {
		return list.back();
	}
	void pop_front() {
		list.pop_front();
	}
	void pop_back() {
		list.pop_back();
	}
	int size() const {
		return list.size();
	}
	bool empty() const {
		return list.empty();
	}
};

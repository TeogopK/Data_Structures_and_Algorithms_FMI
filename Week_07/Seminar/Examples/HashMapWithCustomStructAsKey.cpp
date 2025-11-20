#include <iostream>
#include <unordered_map>
#include <unordered_set>

struct MyStruct {
	int a;
	int b;

	bool operator==(const MyStruct& other) const {
		return a == other.a && b == other.b;
	}
};

struct MyStructHash {
	size_t operator()(const MyStruct& s) const {
		return std::hash<int>()(s.a) ^ std::hash<int>()(s.b);
	}
};

int main() {
	// hashmap requires calculating hashcodes and equal operator
	std::unordered_map<MyStruct, int, MyStructHash> myMap;

	MyStruct s1{ 1, 2 };
	myMap[s1] = 3;

	// number of buckets
	// myMap.bucket_count();
	// adjust the max load factor
	// myMap.max_load_factor(5);

	for (auto& kvp : myMap) {
		std::cout << kvp.first.a << " " << kvp.first.b << " " << kvp.second << std::endl;
	}
}

#include <iostream>
#include <set>
#include <map>

struct MyStruct {
	int a;
	int b;

	bool operator<(const MyStruct& other) const {
		return a > other.a && b > other.b;
	}
};

//struct MyStructComparator {
//	bool operator()(const MyStruct& lhs, const MyStruct& rhs) const {
//		return lhs.a < rhs.a;
//	}
//};

int main() {
  //v1 with op<
	std::map<MyStruct, int> s;
  
  // v2 with comparator and without op<
	//std::map<MyStruct, int, MyStructComparator> s;
	MyStruct m1 = { 1, 2 };
	MyStruct m2 = { 2, 3 };
	MyStruct m3 = { 3, 4 };

	s.insert({ m1, 4 });
	s.insert({ m1, 5 });
	s[m2] = 5;

	auto it = s.find(m1);
	if(it != s.end()) {
		std::cout << it->second << std::endl;
	}

	// will return default value
	std::cout << s[m3];
	
	// sorted iteration
	for(auto& kvp : s) {
		std::cout << kvp.second << std::endl;
	}
}

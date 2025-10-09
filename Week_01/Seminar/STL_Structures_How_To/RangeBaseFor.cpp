#include <iostream>
#include <vector>

struct MyContainer {
private:
    std::vector<int> v = { 1, 2, 3 };

public:
    auto begin() { // should return iterator or pointer
		return v.begin();
	}
    // when using iterator, end is point to the element after the last element
    auto end() { // should return iterator or pointer
        return v.end();
    }
};

int main() {
    std::vector<int> v1(100, 0);

    for (auto iter = v1.begin(); iter != v1.end(); iter++) {
        std::cout << *iter;
    }
    std::cout << std::endl;

    for(auto& elem : v1) {
		std::cout << elem;
	}
    std::cout << std::endl;

    int arr[100] = { 0 };
    for(auto& elem : arr) { // & !!!
		std::cout << elem;
	}

    std::cout << std::endl;
    MyContainer c;
    for(auto& elem : c) {
		std::cout << elem;
	}
    
    // error
    // int* p = new int[100];
    // for (auto& elem : p) {}
}
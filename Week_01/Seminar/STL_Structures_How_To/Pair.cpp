#include <iostream>
#include <utility> // std::pair
#include <string>

int main() {
	// used in maps/unordered_maps
	// used in returning multiple values from a function
	std::pair<int, std::string> p0 = std::make_pair(0, "hello");

	std::pair<int, int> p1;
	p1.first = 1;
	p1.second = 2;
	std::cout << p1.first << " " << p1.second << std::endl;

	std::pair<int, int> p2(3, 4);
	std::cout << p2.first << " " << p2.second << std::endl;

	// std::make_pair is template function
	auto p3 = std::make_pair(5, 6);
	std::cout << p3.first << " " << p3.second << std::endl;

	auto p5 = std::make_pair(1, 2);
	p5.swap(p3);
	std::cout << p5.first << " " << p5.second << std::endl;

	// first compares first element, if equal then compares second element
	if(p1 == p2) {
		std::cout << "p1 is equal to p2" << std::endl;
	} else {
		std::cout << "p1 is not equal to p2" << std::endl;
	}
}
#include <iostream>
#include <tuple>

int main() {
	// like a pair but can hold more elements
	std::tuple<int, double, char> t(1, 2.5, 'c');
	// std::make_tuple;
	// set
	std::get<0>(t) = 10;
	// get
	std::cout << std::get<0>(t) << std::endl;
	// t.swap - swap two tuples
	// auto [a, b, c] = t; - c++ 17
}
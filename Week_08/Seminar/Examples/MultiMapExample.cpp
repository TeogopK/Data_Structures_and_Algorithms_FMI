#include <iostream>
#include <map>
#include <set>

int main() {
	std::multimap<int, int> mymap;

	mymap.insert(std::pair<int, int>(1, 10));
	mymap.insert(std::pair<int, int>(2, 20));
	mymap.insert(std::pair<int, int>(1, 30));

	std::cout << "mymap contains:\n";
	for(auto& kvp: mymap) {
		std::cout << kvp.first << " => " << kvp.second << '\n';
	}
}

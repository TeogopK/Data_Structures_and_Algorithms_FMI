#include <string>
#include <iostream>

auto readWithoutWhitespace() {
	std::string temp;
	std::cin >> temp;
	return temp;
}

auto readWithWhitespace() {
	std::string temp;
	std::getline(std::cin, temp);
	return temp;
}

int main() {
	auto str = readWithWhitespace();
	std::cout << str;
	std::cout << str.c_str() << std::endl; // Convert to C-style string - returns const char*
	std::cout << str.length() << std::endl; // Get length of string
	std::cout << str.size() << std::endl; // Get length of string
	std::cout << str.capacity() << std::endl; // Get capacity of string
	// str.push_back('a'); // Add character to end of string
	// str.append("aa"); // appends string or char*
	// str.at(0); // Access character at index
	// str[0]; // Access character at index
	// str.back(); // Access last character
	// str.front(); // Access first character
	// str.clear(); // Clear string
	// str.empty(); // Check if string is empty
	// str.erase(0, 1); // Erase characters from index to index
	std::cout << str.find("aaa"); // Find first occurrence of string or char*
	str.pop_back(); // Remove last character
	str.replace(0, 1, "a"); // Replace characters from index to index with string or char*
	str.cbegin(); // Get const iterator to beginning
	str.cend(); // Get const iterator to end
	str.begin(); // Get iterator to beginning
	str.end(); // Get iterator to end
	str.insert(0, "a"); // Insert string or char* at index
	str.reserve(10); // Reserve memory for string
	str.resize(10); // Resize string
	str.shrink_to_fit(); // Shrink capacity to fit size
	//...
}
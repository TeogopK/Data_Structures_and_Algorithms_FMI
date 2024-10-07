#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;
    std::cout << v.size() << " " << v.capacity() << std::endl; // 0 0
    v.push_back(1);
    std::cout << v.size() << " " << v.capacity() << std::endl; // 1 1
    // resize ratio: 1.5

    // vector
    auto vector = std::vector<int>(10, 0); // Initial size = 10, Initialize with 0s
    vector[0] = 1;                         // Access index
    vector.push_back(1);                   // Append new item
    vector.pop_back();                     // Remove last item, throws if empty
    vector.clear();                        // Remove all elements
    vector.resize(5);                      // Change size
    vector.reserve(10);                    // Change capacity
    vector[0];                             // Access index, throws if missing
    vector.at(1);                          // Access index == vec[1], throws if empty
    vector.front();                        // First item == vec[0], throws if empty
    vector.back();                         // Last item == vec[vec.size() - 1], throws if empty
    vector.insert(vector.begin() + 2, 20); // Insert 20 at index 2
    vector.erase(vector.begin() + 2);      // Remove item at index 2

    // Iterate using index
    for (int i = 0; i < vector.size(); i++)
        vector[i];

    // Iterate using iterator
    for (auto it = vector.begin(); it != vector.end(); it++)
        *it;

    // Iterate using iterator
    for (int& element : vector)
        element;
}
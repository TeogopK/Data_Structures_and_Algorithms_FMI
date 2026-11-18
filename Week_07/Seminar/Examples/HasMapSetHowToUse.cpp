#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <map>

int main() {

    // array [1 , 4, 2 ,2 , 5, 6, 7] size = 7
    // set { 1, 4, 2, 5, 6, 7 } size = 6
    
    // set => { a, b, c, d}
    // unique key (key acts also as value)
    std::unordered_set<std::string> s;

    // { a: 1, b: 4, c: 4, d: 4 }
    // unique key!!!
    std::unordered_map<std::string, int> m;

    // findValueByKey => O(1)
    // findKeyByValue => O(n)

    m["Georgi"] = 125;
    auto iter = m.find("Georgi");
    // kvp => key-value pair
    std::cout << (*iter).first;    
    std::cout << (*iter).second;
    m["Ivan"] = 25;
    m.insert({ "Maria", 30 });

    // access
    std::cout << m["Ivan"] << '\n'; // undefined value if missing
    std::cout << m.at("Maria") << '\n'; // throws error if missing

    // update
    m["Ivan"] = 26;

    // find / count
    if (m.find("Georgi") != m.end())
        std::cout << "Georgi found\n";
    std::cout << m.count("Petar") << '\n';

    // erase
    m.erase("Maria");

    // iterate
    for (const auto& [key, value] : m)
        std::cout << key << ": " << value << '\n';

    // size / empty / clear
    std::cout << m.size() << '\n';
    m.clear();
    std::cout << m.empty() << '\n';
}

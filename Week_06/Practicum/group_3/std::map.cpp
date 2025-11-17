#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> mp; //sorts by default by keys
    map<int, string, less<int>> mp; // same
    map<int, string, greater<int>> mp; // sorts in custom order

    // 1. Insert elements
    mp[1] = "one";          // operator[] for change -> override the value
    mp.insert({2, "two"});  // insert a pair - DOES NOT override the value 
    mp.emplace(3, "three"); // construct in-place - same as insert, but more effitient

    // 2. Access elements
    cout << mp[2] << endl; // "two"
    cout << mp.at(3) << endl; // "three" // mp.at(1) throws exception if key not found

    // 3. Check size and emptiness
    cout << mp.size() << endl;
    cout << (mp.empty() ? "empty" : "not empty") << endl;

    // 4. Find element
    auto it = mp.find(2);
    if (it != mp.end()) cout << it->first << " => " << it->second << endl;

    // 5. Erase element
    mp.erase(1);       // by key
    mp.erase(mp.begin()); // by iterator

    // 6. Iterate
    for (auto& [k, v] : mp) {
        cout << k << " -> " << v << endl;
    }
    for (auto& it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // 7. Clear map
    mp.clear();
}

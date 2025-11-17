#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> mp; //keys are NOT sorted
    
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
    mp.erase(mp.begin()); // by no guarantee which is the begin()

    // 6. Clear map
    mp.clear();

    // 7. Iterate
    for (auto& [k, v] : mp) {
        cout << k << " -> " << v << endl;
    }
    for (auto& it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    //Example: Order not guaranteed
    mp[11] = "";
    mp[2] = "";
    mp[123] = "";
    mp[1] = "";
    mp[0] = "";
    for (auto& it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    //WARNING!
    cout << "ECHO" <<  mp[12421] << "ECHO";
    //by default accessing map/set with op[] will return the neutral element, not throwing exception, this is a problem to be careful for
}

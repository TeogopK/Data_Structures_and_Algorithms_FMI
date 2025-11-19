#include <iostream>
#include <set>
using namespace std;

struct Descending {
    bool operator()(const string &a, const string &b) const {
        return a > b;
    }
};

//The STL std::set is implemented with red-black tree which is self balancing binary tree
int main() {
    set<string> s; //sort by key 
    set<string, less<string>> s2; //the same
    set<string, greater<string>> s3; //sort by desc order
    set<string, Descending> s4; //sort custom

    // 1. Insert
    s.insert("a");
    s.insert("b");
    s.emplace("c");

    // 2. Find
    if (s.find("b") != s.end()) cout << "Found b" << endl;

    // 3. Check size
    cout << s.size() << endl;

    // 4. Erase
    s.erase("c");        // by key
    s.erase(s.begin()); // by iterator

    // 5. Iterate
    for (auto& x : s) cout << x << " ";
    cout << endl;

    // 6. Clear
    s.clear();

    //Example:
    s.insert("m");
    s.insert("i");
    s.insert("a");
    s.insert("z");
    for(auto& el: s) {
        cout << el << " ";
    }
}

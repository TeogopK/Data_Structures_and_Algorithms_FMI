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
    set<string, less<string>> s; //the same
    set<string, greater<string>> s; //sort by desc order
    set<string, Descending> s; //sort custom

    // Insert
    s.insert("a");
    s.insert("b");
    s.emplace("c");

    // Find
    if (s.find("b") != s.end()) cout << "Found b" << endl;

    // Check size
    cout << s.size() << endl;

    // Erase
    s.erase("c");        // by key
    s.erase(s.begin()); // by iterator

    // Iterate
    for (auto& x : s) cout << x << " ";
    cout << endl;

    // Clear
    s.clear();

    s.insert("m");
    s.insert("i");
    s.insert("a");
    s.insert("z");
    for(auto& el: s) {
        cout << el << " ";
    }
}

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;

    // Insert
    us.insert(10);
    us.emplace(5);

    // Find
    if (us.find(10) != us.end()) cout << "Found 10" << endl;

    // Erase
    us.erase(5);

    // Iterate
    for (int x : us) cout << x << " ";
    cout << endl;

    // Size and clear
    cout << us.size() << endl;
    us.clear();
}

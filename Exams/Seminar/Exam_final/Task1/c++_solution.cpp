#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> count;

    int triplets = 0;
    for (int i = 0; i < n; i++) {
        string color;
        cin >> color;
        count[color]++;
    }

    for (auto& kvp : count) {
        triplets += kvp.second / 3;
    }

    cout << triplets << endl;
}

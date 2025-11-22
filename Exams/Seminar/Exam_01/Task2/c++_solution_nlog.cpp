#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int number;
    int index;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Pair> pairs(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pairs[i].number;
        pairs[i].index = i;
    }
    
    // sort by value
    std::sort(pairs.begin(), pairs.end(),
        [](const Pair& a, const Pair& b) {
            return a.number > b.number;
        });

    std::vector<int> result(n);

    int count = 0;
    int prevNumber = -1;
    for (int i = 0; i < n; i++) {
        if (pairs[i].number != prevNumber) {
            count = i;
            prevNumber = pairs[i].number;
        }

        result[pairs[i].index] = count;
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
}

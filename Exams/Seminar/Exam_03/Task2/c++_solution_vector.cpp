#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Решение 1: Използване на vector и upper_bound
// Добавяме елементите във вектор, сортираме го и търсим с upper_bound

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int target;
    cin >> target;

    // Сортираме вектора
    sort(nums.begin(), nums.end());

    // upper_bound връща итератор към първия елемент строго по-голям от target
    auto it = upper_bound(nums.begin(), nums.end(), target);

    if (it == nums.end()) {
        cout << "NO" << endl;
    }
    else {
        cout << *it << endl;
    }

    return 0;
}

// Сложност:
// Време: O(N*logN) за сортиране + O(logN) за upper_bound = O(N*logN)
// Памет: O(N) за вектора
